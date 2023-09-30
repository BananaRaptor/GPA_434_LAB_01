#pragma once
#include <EzGame>

class Arena
{
	private:
		const float mMinimumSize = 50;
		const float mMaximumSize = 2000;
		float mWidth = 0 ;
		float mHeigth = 0;
		ezgame::Vect2d restrictedVector(const ezgame::Vect2d unmodifiedVect) const;
		ezgame::Vect2d warpedVector(const ezgame::Vect2d unmodifiedVect) const;

	public:

		Arena(float width, float heigth);

		Arena();

		float getWidth();

		float getHeigth();

		ezgame::Vect2d getCenter() const;

		float smallerSize() const;

		float largerSize() const;

		ezgame::Vect2d restrictedPosition(const ezgame::Vect2d & position) const;

		ezgame::Vect2d warpedPosition(const ezgame::Vect2d & position) const;

		void tic(float elapsedTime);

		void draw(ezgame::Screen& screen);

};

