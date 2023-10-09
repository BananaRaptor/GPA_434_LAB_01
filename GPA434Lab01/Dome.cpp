#include "Dome.h"

Dome::Dome(Arena &arena)
{
	float radius = (arena.getWidth() > arena.getHeigth()) ? arena.getHeigth() / 4 : arena.getWidth() / 4;
	mShape = ezgame::Circle(radius, ezgame::Vect2d(arena.getWidth() / 2, arena.getHeigth() / 2), ezgame::Color(ezgame::Color::Yellow));
	mShape.setEdge(mEdgeSize);
	mShape.setEdge(ezgame::Color(ezgame::Color::Red));
}

float Dome::radius() const
{
	return mShape.radius();
}

ezgame::Vect2d Dome::position() const
{
	return mShape.position();
}

ezgame::Circle Dome::circle() const
{
	return mShape;
}

ezgame::Color Dome::color() const
{
	return mShape.fillColor();
}

void Dome::setColor(ezgame::Color &color)
{
	ezgame::Color lighterColor = ezgame::Color(color.red(), color.green(), color.blue(), mEdgeColorLighterRatio);
	mShape.setColors(lighterColor, color);
	return;
}

void Dome::tic(float elapsedTime)
{
}

void Dome::draw(ezgame::Screen &screen)
{
	screen.draw(mShape);
}
