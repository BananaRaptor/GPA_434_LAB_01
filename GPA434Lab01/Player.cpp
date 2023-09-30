#include "Player.h"
#include <cmath>


bool Player::isCollidingCircle(ezgame::Circle circle)
{
	float distance = sqrt(pow(mPlayerShape.position().x() - circle.position().x(), 2) + pow(mPlayerShape.position().y() - circle.position().y(), 2));
	return distance < (circle.radius() + mPlayerShape.radius());
}

Role Player::role()
{
	return mRole;
}

std::string Player::name()
{
	return mName;
}

float Player::speed()
{
	return mSpeed;
}

size_t Player::hitScore()
{
	return mHitScore;
}

float Player::timeAsDefender()
{
	return mTimeAsDefender;
}

float Player::timeAsContender()
{
	return mTimeAsContender;
}

BorderManagement Player::borderManagement()
{
	return mBorderManagement;
}

bool Player::isColliding(ezgame::Circle& otherCircle)
{
	return isCollidingCircle(otherCircle);
}

bool Player::isColliding(Player& player)
{
	return isCollidingCircle(player.mPlayerShape);
}

bool Player::isColliding(Dome& dome)
{
	return isCollidingCircle(dome.circle());
}

void Player::tic(const ezgame::Keyboard& keyboard, const float elapsedTime, const Arena& arena)
{
	addTimeAsRole(elapsedTime);
	movePlayer(keyboard, arena);
	mBorderManagementShape.position().set(mPlayerShape.position().x(), mPlayerShape.position().y());
	
}

void Player::draw(ezgame::Screen& screen)
{
	screen.draw(mPlayerShape);
	ezgame::Color newColor = (mBorderManagement == BorderManagement::Restrict) ? ezgame::Color::White : ezgame::Color::Black;
	mBorderManagementShape.setColors(newColor, newColor);
	screen.draw(mBorderManagementShape);
}

void Player::addHit()
{
	mHitScore++;
}

void Player::removeHit()
{
	mHitScore--;
}

void Player::adjustSize(float relativeSize)
{
	mPlayerShape.setRadius(mPlayerShape.radius() * relativeSize);
}

void Player::adjustSpeed(float relativeSpeed)
{
	mSpeed *= relativeSpeed;
}

void Player::setBorderManagement(BorderManagement borderManagement)
{
	mBorderManagement = borderManagement;
}

void Player::movePlayer(const ezgame::Keyboard& keyboard, const Arena& arena)
{
	mPlayerShape.move(mDirectionKeyMapping.directionFromKeyboard(keyboard) * mSpeed);
	ezgame::Vect2d unMovedPosition = mPlayerShape.position();
	ezgame::Vect2d tempPosition = ezgame::Vect2d(0, 0);
	switch (mBorderManagement)
	{
		case BorderManagement::Restrict:
			tempPosition = arena.restrictedPosition(unMovedPosition);
			mPlayerShape.setPosition(tempPosition);
			mBorderManagementShape.setPosition(tempPosition);
			break;
		case BorderManagement::Warping:
			tempPosition = arena.warpedPosition(unMovedPosition);
			mPlayerShape.setPosition(tempPosition);
			mBorderManagementShape.setPosition(tempPosition);
			break;
		default:
			break;
	}
}

void Player::addTimeAsRole(float elapsedTime)
{
	switch (mRole)
	{
		case Role::Defender:
			mTimeAsDefender += elapsedTime;
			break;
		case Role::Contender:
			mTimeAsContender += elapsedTime;
			break;
		default:
			break;
	}
}
