#pragma once
#include <EzGame>
#include "Arena.h"
#include "Dome.h"
#include "Player.h"

class GameEngine
{
    public:
        GameEngine();

        float width() const { return 800.0f; }
        float height() const { return 600.0f; }
        std::string title() const { return "Dome Defender"; }
        std::string iconFileName() const { return ""; }

        bool provessEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
            player1.tic(keyboard, timer.secondSinceLastTic(), gameArena);
            return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
        }
        void processDisplay(ezgame::Screen& screen) {
            gameArena.draw(screen);
            dome.draw(screen);
            player1.draw(screen);
        }

    private:
        ezgame::Text mText;
        ezgame::Circle mCircle;
        Arena gameArena = Arena(width(),height());
        Dome dome = Dome(gameArena);
        Player player1 = Player(Role::Defender, std::string("Player 1"), ezgame::Color(ezgame::Color::Aqua), DirectionKeyMapping(StandardMapping::WASD));
   

};
