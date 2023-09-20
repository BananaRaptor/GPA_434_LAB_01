#pragma once
#include <EzGame>
#include "Arena.h"

class GameEngine
{
    public:
        GameEngine();

        float width() const { return 800.0f; }
        float height() const { return 600.0f; }
        std::string title() const { return "Dome Defender"; }
        std::string iconFileName() const { return ""; }

        bool provessEvents(ezgame::Keyboard const& keyboard, ezgame::Timer const& timer) {
            if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Space)) {
                mCircle.move(ezgame::Vect2d::fromRandomized() * 2.5f);
            }
            if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Left)) {
                mCircle.move(ezgame::Vect2d::Vect2d(-1,0) * 2.5f);
            }
            if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Right)) {
                mCircle.move(ezgame::Vect2d::Vect2d(1, 0) * 2.5f);
            }
            if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Up) {
                mCircle.move(ezgame::Vect2d::Vect2d(0, 1) * 2.5f);
            }
            if (keyboard.isKeyPressed(ezgame::Keyboard::Key::Right)) {
                mCircle.move(ezgame::Vect2d::Vect2d(1, 0) * 2.5f);
            }
            return !keyboard.isKeyPressed(ezgame::Keyboard::Key::Escape);
        }
        void processDisplay(ezgame::Screen& screen) {
            screen.clear();
            screen.draw(mText);
            screen.draw(mCircle);
        }

    private:
        ezgame::Text mText;
        ezgame::Circle mCircle;
        Arena gameArena = Arena(width(),height());

        

};
