#pragma once
#include <EzGame>

class Arena
{
	private:
		const float mMinimumSize = 50;
		const float mMaximumSize = 2000;
		float mWidth = 0 ;
		float mHeigth = 0;
		ezgame::Vect2d restrictedVector(ezgame::Vect2d unmodifiedVect);
		ezgame::Vect2d warpedVector(ezgame::Vect2d unmodifiedVect);

	public:

		Arena(float width, float heigth);

		Arena();

		float getWidth();

		float getHeigth();

		ezgame::Vect2d getCenter();

		float smallerSize();

		float largerSize();

		ezgame::Vect2d restrictedPosition(ezgame::Vect2d unmodifiedVect);

		ezgame::Vect2d warpedPosition(ezgame::Vect2d unmodifiedVect);

};

