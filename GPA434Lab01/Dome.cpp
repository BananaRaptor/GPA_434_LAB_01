#include "Dome.h"


Dome::Dome(Arena& arena)
{
	float radius = (arena.getWidth() > arena.getHeigth()) ? arena.getHeigth() / 4 : arena.getWidth() / 4;
	 mShape = ezgame::Circle(radius, ezgame::Vect2d(arena.getWidth() / 2, arena.getHeigth() / 2), ezgame::Color(ezgame::Color::Yellow));
	 mShape.setEdge(mEdgeSize);
}

float Dome::radius()
{
	return mShape.radius();
}

ezgame::Vect2d Dome::position()
{
	return mShape.position();
}

ezgame::Circle Dome::circle()
{
	return mShape;
}

ezgame::Color Dome::color()
{
	return mShape.fillColor();
}

void Dome::setColor(ezgame::Color& color)
{
	ezgame::Color lighterColor = ezgame::Color(color.red() * mEdgeColorLighterRatio, color.green() * mEdgeColorLighterRatio, color.red() * mEdgeColorLighterRatio);
	mShape.setColors(color, lighterColor);
	return;
}

void Dome::tic(float elapsedTime)
{
}

void Dome::draw(ezgame::Screen& screen)
{
	screen.draw(mShape);
}
