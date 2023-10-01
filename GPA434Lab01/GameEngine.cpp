#include "GameEngine.h"
#include <EzGame>

bool GameEngine::provessEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer)
{
    player0.tic(keyboard, timer.secondSinceLastTic(), gameArena);
    player1.tic(keyboard, timer.secondSinceLastTic(), gameArena);
    modifier.tic(player0, player1, gameArena, dome);
    scoreManager.tic(player0, player1);
    if(player0.role() == Role::Defender) {
        ezgame::Color  tempColor = player0.color();
        dome.setColor(tempColor);
    }else {
        ezgame::Color  tempColor = player1.color();
        dome.setColor(tempColor);
    }

    handleDefenderWin();
    handleContenderWin();
    if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Enter)) {
        resetGame();
    }
    return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
}

void GameEngine::resetGame()
{
    player0.~Player();
    player1.~Player();
    modifier.~Modifier();
    new(&player0) Player(Role::Defender, std::string("Player 0"), ezgame::Color(ezgame::Color::Red), DirectionKeyMapping(StandardMapping::WASD));
    new(&player1) Player(Role::Contender, std::string("Player 1"), ezgame::Color(ezgame::Color::Blue), DirectionKeyMapping(StandardMapping::Arrows));
    new(&modifier) Modifier(gameArena, dome);
}

void GameEngine::handleContenderWin()
{
    if (player0.isColliding(dome) && player0.role() == Role::Contender) {
        player0.newMatch(true, true, gameArena, dome);
        player1.newMatch(false, true, gameArena, dome);
    }
    if (player1.isColliding(dome) && player1.role() == Role::Contender) {
        player0.newMatch(false, true, gameArena, dome);
        player1.newMatch(true, true, gameArena, dome);
    }
}

void GameEngine::processDisplay(ezgame::Screen& screen)
{
    gameArena.draw(screen);
    dome.draw(screen);
    player0.draw(screen);
    player1.draw(screen);
    modifier.draw(screen);
    scoreManager.draw(screen);
}

void GameEngine::handleDefenderWin()
{
    if (player0.isColliding(player1)) {
        if (player0.role() == Role::Defender) {
            player0.newMatch(true, false, gameArena, dome);
            player1.newMatch(false, false, gameArena, dome);
        }
        else {
            player0.newMatch(false, false, gameArena, dome);
            player1.newMatch(true, false, gameArena, dome);
        }
    }
}
