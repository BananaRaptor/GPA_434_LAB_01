#pragma once
#include <EzGame>
#include "Arena.h"
#include "Dome.h"
#include "Player.h"
#include "Modifier.h"
#include "ScoreManager.h"

class GameEngine
{
    public:
        GameEngine() {
            scoreManager.setup(player0, player1, gameArena);
            resetGame(player0, player1);
            player0.newMatch(false,false,gameArena,dome);
            player1.newMatch(false, false, gameArena, dome);
        };

        float width() const { return 1200.0f; }
        float height() const { return 800.0f; }
        std::string title() const { return "Dome Defender"; }
        std::string iconFileName() const { return ""; }

        bool processEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer);
        void processDisplay(ezgame::Screen& screen);

    private:
        ezgame::Text mText;
        ezgame::Circle mCircle;
        Arena gameArena = Arena(width(),height());
        Dome dome = Dome(gameArena);
        Player player0 = Player(Role::Defender, std::string("Player 0"), ezgame::Color(ezgame::Color::Red), DirectionKeyMapping(StandardMapping::WASD));
        Player player1 = Player(Role::Contender, std::string("Player 1"), ezgame::Color(ezgame::Color::Blue), DirectionKeyMapping(StandardMapping::Arrows));
        Modifier modifier = Modifier(gameArena, dome);
        ScoreManager scoreManager = ScoreManager();

        void resetGame();
        void resetGame(Player& defender, Player& pretender);
        void handleDefenderWin(Player& defender, Player& pretender);
        void handleContenderWin(Player& defender, Player& pretender);
        bool isAppStillRunning(ezgame::Keyboard const& keyboard);
        void manageEndMatch();
        void manageEndMatch(Player& defender, Player& pretender);
        void manageEndGame(ezgame::Keyboard const& keyboard);
        void setDomeColorFromPlayer(Player& defender);

};
