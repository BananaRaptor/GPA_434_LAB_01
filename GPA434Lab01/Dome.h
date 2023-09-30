#pragma once
#include <EzGame>
#include "Arena.h"

class Dome
{
	private:
		const float mEdgeColorLighterRatio = 0.75;
		const float mEdgeSize = 1.5;
		ezgame::Circle mShape;

	public:
		Dome(Arena& arena);

		float radius() const;

		ezgame::Vect2d position();

		ezgame::Circle circle();

		ezgame::Color color();

		void setColor(ezgame::Color& color);

		void tic(float elapsedTime);

		void draw(ezgame::Screen& screen);



};

