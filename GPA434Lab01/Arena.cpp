#include "Arena.h"

Arena::Arena(float width, float heigth)
{
	mWidth = width;
	mHeigth = heigth;
}

Arena::Arena()
{
	mWidth = mMinimumSize;
	mHeigth = mMaximumSize;
}

float Arena::getWidth()
{
	return mWidth;
}

float Arena::getHeigth()
{
	return mHeigth;
}

ezgame::Vect2d Arena::getCenter() const
{

	return ezgame::Vect2d(mWidth/2,mHeigth/2);
}

float Arena::smallerSize() const
{
	return !(mWidth <= mHeigth) ? mHeigth : mWidth;
}


float Arena::largerSize() const
{
	return !(mWidth >= mHeigth) ? mHeigth : mWidth;
}

ezgame::Vect2d Arena::restrictedPosition(const ezgame::Vect2d & position) const
{
	return (position.x() > 0 && position.x() < mWidth && position.y() > 0 && position.y() < mHeigth) ? position : restrictedVector(position);
}

ezgame::Vect2d Arena::warpedPosition(const ezgame::Vect2d & position) const
{
	return (position.x() > 0 && position.x() < mWidth && position.y() > 0 && position.y() < mHeigth) ? position : warpedVector(position);
}

void Arena::tic(float elapsedTime)
{
}

void Arena::draw(ezgame::Screen& screen)
{
	screen.clear();
}

ezgame::Vect2d Arena::restrictedVector(const ezgame::Vect2d unmodifiedVect) const
{
	if (unmodifiedVect.x() < 0) {
		return ezgame::Vect2d(0, unmodifiedVect.y());
	}
	if (unmodifiedVect.x() > mWidth) {
		return ezgame::Vect2d(mWidth, unmodifiedVect.y());
	}
	if (unmodifiedVect.y() < 0) {
		return ezgame::Vect2d(unmodifiedVect.x(), 0);
	}
	if (unmodifiedVect.y() > mHeigth) {
		return ezgame::Vect2d(unmodifiedVect.x(), mHeigth);
	}
	return unmodifiedVect;
}

ezgame::Vect2d Arena::warpedVector(const ezgame::Vect2d unmodifiedVect) const
{
	if (unmodifiedVect.x() < 0) {
		return ezgame::Vect2d(mWidth, unmodifiedVect.y());
	}
	if (unmodifiedVect.x() > mWidth) {
		return ezgame::Vect2d(0, unmodifiedVect.y());
	}
	if (unmodifiedVect.y() < 0) {
		return ezgame::Vect2d(unmodifiedVect.x(), mHeigth);
	}
	if (unmodifiedVect.y() > mHeigth) {
		return ezgame::Vect2d(unmodifiedVect.x(), 0);
	}
	return unmodifiedVect;
}
