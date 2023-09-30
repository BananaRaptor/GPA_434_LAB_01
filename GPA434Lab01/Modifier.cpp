#include "Modifier.h"

Type Modifier::type()
{
	return mType;
}

Effect Modifier::effect()
{
	return mEffect;
}

void Modifier::randomize(const Arena& arena, const Dome& dome)
{
	setType();
	setEffect();
	setPositionOfElements(arena, dome);
}

void Modifier::setPositionOfElements(const Arena& arena, const Dome& dome)
{
	int circleWidth = arena.smallerSize() / 2 - dome.radius();
	float radius = dome.radius() + ezgame::Random::real(0.0, 1.0) * circleWidth;
	float angle = 2 * M_PI * (ezgame::Random::real(0.0, 360.0) / 360);
	ezgame::Vect2d center = arena.getCenter();
	float x = std::cos(angle) * radius + center.x();
	float y = std::sin(angle) * radius + center.y();;
	ezgame::Vect2d newPosition = ezgame::Vect2d(x, y);
	ezgame::Vect2d newPositionText = ezgame::Vect2d(x, y - 2 * mShape.radius());
	ezgame::Vect2d newPositionSecondary = ezgame::Vect2d(x, y + mShape.radius() + mTypeShape.radius());
	mShape.setPosition(newPosition);
	mText.setPosition(newPositionText);
	mText.setAlignment(ezgame::Alignment::CenterCenter);
	mTypeShape.setPosition(newPositionSecondary);
}

void Modifier::tic(Player& player0, Player& player1, const Arena& arena, const Dome& dome)
{
	if(player0.isColliding(mShape) && player1.isColliding(mShape)) {
		randomize(arena,dome);
		return;
	}
	if (player0.isColliding(mShape))
	{
		applyEffect(player0);
		randomize(arena, dome);
		return;
	}
	if (player1.isColliding(mShape))
	{
		applyEffect(player1);
		randomize(arena, dome);
		return;
	}
	return;
}

void Modifier::draw(ezgame::Screen& screen)
{
	screen.draw(mShape);
	screen.draw(mTypeShape);
	screen.draw(mText);
}

void Modifier::applyBonus(Player& player)
{
	switch (mEffect)
	{
		case Effect::Speed:
			player.adjustSpeed(mPlayerSpeedIncrease);
			break;
		case Effect::Size:
			player.adjustSize(mPlayerSizeIncrease);
			break;
		case Effect::Warping:
			player.setBorderManagement(BorderManagement::Warping);
			break;
		case Effect::Hit:
			player.addHit();
			break;
		default:
			break;
	}
}

void Modifier::applyMalus(Player& player)
{
	switch (mEffect)
	{
		case Effect::Speed:
			player.adjustSpeed(mPlayerSpeedDecrease);
			break;
		case Effect::Size:
			player.adjustSize(mPlayerSizeDecrease);
			break;
		case Effect::Warping:
			player.setBorderManagement(BorderManagement::Restrict);
			break;
		case Effect::Hit:
			player.removeHit();
			break;
		default:
			break;
		}
}

void Modifier::applyEffect(Player& player)
{
	switch (mType)
	{
		case Type::Bonus:
			applyBonus(player);
			break;
		case Type::Malus:
			applyMalus(player);
			break;
		default:
			break;
	}
}

void Modifier::setEffect()
{
	mEffect = ezgame::Random::enumerator<Effect>(4);
	switch (mEffect)
	{
		case Effect::Speed:
			mText = ezgame::Text(mTextEffectSpeed, mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultShapeColor);
			break;
		case Effect::Size:
			mText = ezgame::Text(mTextEffectSize, mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultShapeColor);
			break;
		case Effect::Warping:
			mText = ezgame::Text(mTextEffectWarping, mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultShapeColor);
			break;
		case Effect::Hit:
			mText = ezgame::Text(mTextEffectHit, mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultShapeColor);
			break;
		default:
			mText = ezgame::Text("ERROR", mDefaultTextSize, ezgame::Vect2d(0, 0), mDefaultShapeColor);
			break;
	}
}

void Modifier::setType()
{
	mType = ezgame::Random::enumerator<Type>(2);
	mTypeShape = ezgame::Circle(mDefaultTypeShapeSize, ezgame::Vect2d(0, 0), (mType == Type::Bonus) ? mColorTypeBonus : mColorTypeMalus);
}
