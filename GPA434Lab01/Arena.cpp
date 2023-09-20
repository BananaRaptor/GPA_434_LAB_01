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

ezgame::Vect2d Arena::getCenter()
{

	return ezgame::Vect2d(mWidth/2,mHeigth/2);
}

float Arena::smallerSize()
{
	return !(mWidth <= mHeigth) ? mHeigth : mWidth;
}

float Arena::largerSize()
{
	return !(mWidth >= mHeigth) ? mHeigth : mWidth;
}

ezgame::Vect2d Arena::restrictedPosition(ezgame::Vect2d unmodifiedVect)
{
	return (unmodifiedVect.x() > 0 && unmodifiedVect.x() < mWidth && unmodifiedVect.y() > 0 && unmodifiedVect.y() < mHeigth) ? unmodifiedVect : restrictedVector(unmodifiedVect);
}

ezgame::Vect2d Arena::warpedPosition(ezgame::Vect2d unmodifiedVect)
{
	return (unmodifiedVect.x() > 0 && unmodifiedVect.x() < mWidth && unmodifiedVect.y() > 0 && unmodifiedVect.y() < mHeigth) ? unmodifiedVect : warpedVector(unmodifiedVect);
}

ezgame::Vect2d Arena::restrictedVector(ezgame::Vect2d unmodifiedVect)
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
}

ezgame::Vect2d Arena::warpedVector(ezgame::Vect2d unmodifiedVect)
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
}
