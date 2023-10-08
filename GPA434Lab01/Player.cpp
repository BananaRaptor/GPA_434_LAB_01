#include "Player.h"
#include <cmath>

bool Player::isCollidingCircle(ezgame::Circle circle)
{
	float distance = sqrt(pow(mPlayerShape.position().x() - circle.position().x(), 2) + pow(mPlayerShape.position().y() - circle.position().y(), 2));
	return distance < (circle.radius() + mPlayerShape.radius());
}

Role Player::role() const
{
	return mRole;
}

std::string Player::name() const
{
	return mName;
}

ezgame::Color Player::color() const
{
	return mPlayerShape.fillColor();
}

float Player::speed()
{
	return mSpeed;
}

size_t Player::hitScore() const
{
	return mHitScore;
}

float Player::timeAsDefender() const
{
	return mTimeAsDefender;
}

float Player::timeAsContender() const
{
	return mTimeAsContender;
}

BorderManagement Player::borderManagement()
{
	return mBorderManagement;
}

bool Player::isColliding(ezgame::Circle &otherCircle)
{
	return isCollidingCircle(otherCircle);
}

bool Player::isColliding(Player &player)
{
	return isCollidingCircle(player.mPlayerShape);
}

bool Player::isColliding(Dome &dome)
{
	return isCollidingCircle(dome.circle());
}

void Player::tic(const ezgame::Keyboard &keyboard, const float elapsedTime, const Arena &arena)
{
	addTimeAsRole(elapsedTime);
	movePlayer(keyboard, arena, elapsedTime);
	mBorderManagementShape.position().set(mPlayerShape.position().x(), mPlayerShape.position().y());
}

void Player::draw(ezgame::Screen &screen)
{
	screen.draw(mPlayerShape);
	ezgame::Color newColor = (mBorderManagement == BorderManagement::Restrict) ? ezgame::Color::White : ezgame::Color::Black;
	mBorderManagementShape.setColors(newColor, newColor);
	screen.draw(mBorderManagementShape);
}

void Player::newMatch(bool hit, bool swap, Arena &arena, Dome &dome)
{
	if (hit)
	{
		mHitScore++;
	}
	if (swap)
	{
		swapRole();
	}
	positionPlayer(arena, dome);
}

void Player::swapRole()
{
	switch (mRole)
	{
	case Role::Defender:
		mRole = Role::Contender;
		break;
	case Role::Contender:
		mRole = Role::Defender;
		break;
	default:
		break;
	};
}

void Player::positionPlayer(Arena &arena, Dome &dome)
{
	switch (mRole)
	{
	case Role::Defender:
		mPlayerShape.setPosition(arena.getCenter());
		break;
	case Role::Contender:
		positionContender(arena, dome);
		break;
	default:
		break;
	};
}

void Player::positionContender(Arena &arena, Dome &dome)
{
	float angle = 2 * M_PI * (ezgame::Random::real(0.0, 360.0) / 360);
	ezgame::Vect2d center = arena.getCenter();
	float x = std::cos(angle) * arena.smallerSize() / 2 + center.x();
	float y = std::sin(angle) * arena.smallerSize() / 2 + center.y();
	mPlayerShape.setPosition(ezgame::Vect2d(x, y));
}

void Player::addHit()
{
	mHitScore++;
}

void Player::removeHit()
{
	if (mHitScore > 0)
	{
		mHitScore--;
	}
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

void Player::movePlayer(const ezgame::Keyboard &keyboard, const Arena &arena, float elapsedTime)
{
	mPlayerShape.move(mDirectionKeyMapping.directionFromKeyboard(keyboard) * mSpeed * elapsedTime);
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
