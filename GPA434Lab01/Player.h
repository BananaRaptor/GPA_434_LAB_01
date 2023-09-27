#pragma once
#include <EzGame>
#include "Role.h"
#include "BorderManagement.h"
#include "DirectionKeyMapping.h"
#include "Dome.h"

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

		void movePlayer(const ezgame::Keyboard& keyboard, const Arena& arena);

		void addTimeAsRole(float elapsedTime);

		bool isCollidingCircle(ezgame::Circle circle);

	public:
		Player(Role role, const std::string&  name, const ezgame::Color&  color, const DirectionKeyMapping& directionKeyMapping) :
			mRole(role),
			mName(name),
			mPlayerShape(mDefautlPlayerRadius, ezgame::Vect2d(0, 0), color),
			mBorderManagementShape(mDefaultBorderManagementRadius, ezgame::Vect2d(0, 0), ezgame::Color::White),
			mDirectionKeyMapping(directionKeyMapping),
			mBorderManagement(BorderManagement::Warping),
			mHitScore(0),
			mTimeAsContender(0),
			mTimeAsDefender(0),
			mSpeed(mDefautlPlayerSpeed) {
			mSpeed = 2;
		};

		Role role();

		std::string name();

		float speed();

		size_t hitScore();

		float timeAsDefender();

		float timeAsContender();

		BorderManagement borderManagement();

		bool isColliding(ezgame::Circle& otherCircle);

		bool isColliding(Player& player);

		bool isColliding(Dome& dome);

		void tic(const ezgame::Keyboard& keyboard, const float elapsedTime, const Arena& arena);


		void draw(ezgame::Screen& screen);

		void newMatch(bool hit, bool swap, Arena& arena, Dome& dome);

		void addHit();

		void removeHit();

		void adjustSize(float relativeSize);

		void adjustSpeed(float relativeSpeed);

		void setBorderManagement(BorderManagement borderManagement);







};

