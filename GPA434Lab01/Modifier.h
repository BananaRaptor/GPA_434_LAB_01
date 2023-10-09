#pragma once
#define _USE_MATH_DEFINES
#include <ezgame>
#include "Effect.h"
#include "Type.h"
#include "Player.h"
#include <math.h>
#include "BorderManagement.h"


class Modifier
{
	private :
		const float mDefaultTextSize = 25;
		const ezgame::Color mDefaultTextColor = ezgame::Color(1, 1, 1, 0.5);
		const float mDefaultShapeSize = 15;
		const ezgame::Color mDefaultShapeColor = ezgame::Color(0.9, 0.9, 0.9, 1);
		const float mDefaultTypeShapeSize = 5;
		const float mPlayerSizeIncrease = 1.15;
		const float mPlayerSpeedIncrease = 1.15;
		const float mPlayerSizeDecrease = 1/ mPlayerSizeIncrease;
		const float mPlayerSpeedDecrease = 1 / mPlayerSpeedIncrease;
		const ezgame::Color mColorTypeBonus = ezgame::Color::Green;
		const ezgame::Color mColorTypeMalus = ezgame::Color::Red;
		const std::string mTextEffectSpeed = "Speed";
		const std::string mTextEffectSize = "Size";
		const std::string mTextEffectWarping = "Warping";
		const std::string mTextEffectHit= "Hit";
		Type mType;
		Effect mEffect;
		ezgame::Text mText;
		ezgame::Circle mShape;
		ezgame::Circle mTypeShape;

		void applyBonus(Player& player);
		void applyMalus(Player& player);
		void applyEffect(Player& player);
		void setEffect();
		void setType();

	public :
		Modifier(const Arena& arena, const Dome& dome) :
			mType(Type::Bonus),
			mEffect(Effect::Speed),
			mShape(ezgame::Circle(mDefaultShapeSize, ezgame::Vect2d(0, 0), mDefaultShapeColor)),
			mText(ezgame::Text("Default", mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultTextColor, ezgame::Alignment::CenterCenter)),
			mTypeShape(ezgame::Circle(mDefaultTypeShapeSize, ezgame::Vect2d(0, 0),  ezgame::Color::White))
		{
			randomize(arena, dome);
		};
		
		Type type() const;
		Effect effect() const;
		void randomize(const Arena& arena, const Dome& dome);
		void setPositionOfElements(const Arena& arena, const Dome& dome);
		void tic(Player& player0, Player& player1, const Arena& arena, const Dome& dome);
		void draw(ezgame::Screen& screen);



};

