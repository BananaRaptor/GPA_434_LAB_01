#include "GameEngine.h"
#include <EzGame>

GameEngine::GameEngine()
{

	mText = ezgame::Text("Ceci est un test!", 36.0f, ezgame::Vect2d(400.0f, 300.0f), ezgame::Color::White, ezgame::Alignment::CenterCenter);
	mCircle = ezgame::Circle(50.0f, ezgame::Vect2d(400.0f, 450.0f), ezgame::Color::Yellow, ezgame::Color::Red, 5.0f, ezgame::Alignment::CenterCenter);
}

