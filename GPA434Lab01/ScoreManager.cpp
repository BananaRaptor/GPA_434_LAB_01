#include "ScoreManager.h"

ScoreManager::ScoreManager()
{
}

void ScoreManager::setup(const Player& player0, const Player& player1, const Arena& arena)
{
	mPlayer0Name = ezgame::Text(player0.name(), mFontSize, ezgame::Vect2d(mTextPositionHorizontalOffset, mTextPositionVerticalOffset), player0.color().lighter(mFontFillLighterRatio), player0.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);
	mPlayer1Name = ezgame::Text(player1.name(), mFontSize, ezgame::Vect2d(arena.getWidth()-mTextPositionHorizontalOffset,mTextPositionVerticalOffset), player1.color().lighter(mFontFillLighterRatio), player1.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);

	mPlayer0Hit = ezgame::Text(std::to_string(player0.hitScore()), mFontSize, ezgame::Vect2d(mPlayer0Name.position().x(), mPlayer0Name.position().y() + mPlayer0Name.textSize() + mTextPositionVerticalOffset), player0.color().lighter(mFontFillLighterRatio), player0.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);
	mPlayer1Hit = ezgame::Text(std::to_string(player1.hitScore()), mFontSize, ezgame::Vect2d(mPlayer1Name.position().x(), mPlayer1Name.position().y() + mPlayer1Name.textSize() + mTextPositionVerticalOffset), player1.color().lighter(mFontFillLighterRatio), player1.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);

	mPlayer0Time = ezgame::Text(std::to_string(player0.timeAsDefender()), mFontSize, ezgame::Vect2d(mPlayer0Name.position().x(), mPlayer0Hit.position().y() + mPlayer0Hit.textSize() + mTextPositionVerticalOffset), player0.color().lighter(mFontFillLighterRatio), player0.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);
	mPlayer1Time = ezgame::Text(std::to_string(player1.timeAsDefender()), mFontSize, ezgame::Vect2d(mPlayer1Name.position().x(), mPlayer1Hit.position().y() + mPlayer1Hit.textSize() + mTextPositionVerticalOffset), player1.color().lighter(mFontFillLighterRatio), player1.color().darker(mEdgeDarkerRatio), mEdgeDarkerRatio, ezgame::Alignment::TopCenter);

}

void ScoreManager::tic(const Player& player0, const Player& player1)
{
	mPlayer0Hit.setText(std::to_string(player0.hitScore()));
	mPlayer1Hit.setText(std::to_string(player1.hitScore()));
	
	mPlayer0Time.setText(std::to_string(player0.timeAsDefender()));
	mPlayer1Time.setText(std::to_string(player1.timeAsDefender()));
}

void ScoreManager::draw(ezgame::Screen& screen)
{
	screen.draw(mPlayer0Name);
	screen.draw(mPlayer1Name);
	screen.draw(mPlayer0Hit);
	screen.draw(mPlayer1Hit);
	screen.draw(mPlayer0Time);
	screen.draw(mPlayer1Time);
}
