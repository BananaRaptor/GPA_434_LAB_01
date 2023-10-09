#include "GameEngine.h"
#include <EzGame>

bool GameEngine::processEvents(ezgame::Keyboard const &keyboard, ezgame::Timer const &timer)
{
    player0.tic(keyboard, timer.secondSinceLastTic(), gameArena);
    player1.tic(keyboard, timer.secondSinceLastTic(), gameArena);
    modifier.tic(player0, player1, gameArena, dome);
    scoreManager.tic(player0, player1);

    manageEndMatch();
    manageEndGame(keyboard);
    return isAppStillRunning(keyboard);
}

void GameEngine::manageEndMatch()
{
    (player0.role() == Role::Defender) ? manageEndMatch(player0, player1) : manageEndMatch(player1, player0);
}

void GameEngine::manageEndMatch(Player& defender, Player& pretender)
{
    handleDefenderWin(defender, pretender);
    handleContenderWin(defender, pretender);
}

void GameEngine::manageEndGame(ezgame::Keyboard const& keyboard)
{
    if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Enter))
    {
        resetGame();
    }
}

void GameEngine::setDomeColorFromPlayer(Player& defender)
{
    ezgame::Color tempColor = defender.color();
    dome.setColor(tempColor);
}

bool GameEngine::isAppStillRunning(ezgame::Keyboard const& keyboard)
{
    return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
}

void GameEngine::processDisplay(ezgame::Screen &screen)
{
    gameArena.draw(screen);
    dome.draw(screen);
    player0.draw(screen);
    player1.draw(screen);
    modifier.draw(screen);
    scoreManager.draw(screen);
}


void GameEngine::resetGame()
{
    (player0.role() == Role::Defender) ? resetGame(player0, player1) : resetGame(player1, player0);
}

void GameEngine::resetGame(Player& defender, Player& pretender)
{
    pretender.newGame(Role::Contender, gameArena, dome);
    defender.newGame(Role::Defender, gameArena, dome);
    setDomeColorFromPlayer(defender);
    modifier.~Modifier();
    new (&modifier) Modifier(gameArena, dome);
}

void GameEngine::handleDefenderWin(Player& defender, Player& pretender)
{
    if (defender.isColliding(pretender))
    {
        defender.newMatch(true, false, gameArena, dome);
        pretender.newMatch(false, false, gameArena, dome);
    }
}

void GameEngine::handleContenderWin(Player& defender, Player& pretender)
{
    if (pretender.isColliding(dome))
    {
        pretender.newMatch(true, true, gameArena, dome);
        defender.newMatch(false, true, gameArena, dome);
        setDomeColorFromPlayer(pretender);
    }
}
