#pragma once
#include <EzGame>
#include "Player.h"
#include "Arena.h"

class ScoreManager
{
	private:
		const float mTextPositionHorizontalOffset = 150;
		const float mTextPositionVerticalOffset = 25;
		const float mTextPositionInterlineSpacing = 15;
		const float mFontSizeRatioNameHitTime = 0.75;
		const float mFontSize = 54;
		const float mFontEdgeSize = 2.5;
		const float mFontFillLighterRatio = 0.5;
		const float mFontAlpha = 0.75;
		const float mEdgeDarkerRatio = 0.5;
		const float mEdgeAlpha = 0.95;
		ezgame::Text mPlayer0Name;
		ezgame::Text mPlayer0Hit;
		ezgame::Text mPlayer0Time;
		ezgame::Text mPlayer1Name;
		ezgame::Text mPlayer1Hit;
		ezgame::Text mPlayer1Time;
	
	public:
		ScoreManager();

		void setup(const Player & player0, const Player& player1, const Arena & arena);

		void tic(const Player& player0, const Player& player1);

		void draw(ezgame::Screen & screen);

};

