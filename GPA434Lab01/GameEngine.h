#pragma once
#include <EzGame>
#include "Arena.h"
#include "Dome.h"
#include "Player.h"
#include "Modifier.h"

class GameEngine
{
    public:
        GameEngine();

        float width() const { return 800.0f; }
        float height() const { return 600.0f; }
        std::string title() const { return "Dome Defender"; }
        std::string iconFileName() const { return ""; }

        bool provessEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
            player0.tic(keyboard, timer.secondSinceLastTic(), gameArena);
            player1.tic(keyboard, timer.secondSinceLastTic(), gameArena);
            modifier.tic(player0, player1, gameArena, dome);
            return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
        }
        void processDisplay(ezgame::Screen& screen) {
            gameArena.draw(screen);
            dome.draw(screen);
            player0.draw(screen);
            player1.draw(screen);
            modifier.draw(screen);
        }

    private:
        ezgame::Text mText;
        ezgame::Circle mCircle;
        Arena gameArena = Arena(width(),height());
        Dome dome = Dome(gameArena);
        Player player0 = Player(Role::Defender, std::string("Player 1"), ezgame::Color(ezgame::Color::Aqua), DirectionKeyMapping(StandardMapping::WASD));
        Player player1 = Player(Role::Contender, std::string("Player 1"), ezgame::Color(ezgame::Color::Aqua), DirectionKeyMapping(StandardMapping::Arrows));
        Modifier modifier = Modifier(gameArena, dome);
   

};
