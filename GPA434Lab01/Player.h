#pragma once
#define _USE_MATH_DEFINES
#include <EzGame>
#include "Role.h"
#include "BorderManagement.h"
#include "DirectionKeyMapping.h"
#include "Dome.h"
#include <math.h>

class Player
{
	private: 
		const float mDefautlPlayerRadius = 25;
		const float mDefautlPlayerSpeed = 250;
		const float mDefaultBorderManagementRadius = 5;
		Role mRole;
		std::string mName;
		float mSpeed;
		ezgame::Circle mPlayerShape;
		ezgame::Circle mBorderManagementShape;
		size_t mHitScore;
		float mTimeAsDefender;
		float mTimeAsContender;
		BorderManagement mBorderManagement;
		DirectionKeyMapping mDirectionKeyMapping;

		void movePlayer(const ezgame::Keyboard& keyboard, const Arena& arena, float elaspedTime);

		void addTimeAsRole(float elapsedTime);

		bool isCollidingCircle(ezgame::Circle circle) const;

		void swapRole();

		void positionPlayer(Arena& arena, Dome& dome);

		void positionContender(Arena& arena, Dome& dome);

	public:
		Player(Role role, const std::string&  name, const ezgame::Color&  color, const DirectionKeyMapping& directionKeyMapping) :
			mRole(role),
			mName(name),
			mPlayerShape(mDefautlPlayerRadius, ezgame::Vect2d(0, 0), color),
			mBorderManagementShape(mDefaultBorderManagementRadius, ezgame::Vect2d(0, 0), ezgame::Color::White),
			mDirectionKeyMapping(directionKeyMapping),
			mBorderManagement(BorderManagement::Restrict),
			mHitScore(0),
			mTimeAsContender(0),
			mTimeAsDefender(0),
			mSpeed(mDefautlPlayerSpeed) {
		};

		Role role() const;

		std::string name() const;

		ezgame::Color color() const;

		float speed() const;

		size_t hitScore() const;

		float timeAsDefender() const;

		float timeAsContender() const;

		BorderManagement borderManagement() const;

		bool isColliding(ezgame::Circle& otherCircle) const;

		bool isColliding(Player& player) const;

		bool isColliding(Dome& dome) const;

		void tic(const ezgame::Keyboard& keyboard, const float elapsedTime, const Arena& arena);

		void draw(ezgame::Screen& screen);

		void newMatch(bool hit, bool swap, Arena& arena, Dome& dome);

		void newGame(Role role, Arena arena, Dome dome);

		void addHit();

		void removeHit();

		void adjustSize(float relativeSize);

		void adjustSpeed(float relativeSpeed);

		void setBorderManagement(BorderManagement borderManagement);







};

