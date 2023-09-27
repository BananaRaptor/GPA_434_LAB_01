#pragma once
#include <EzGame>
#include "Role.h"
#include "BorderManagement.h"
#include "DirectionKeyMapping.h"

class Player
{
	private: 
		const float mDefautlPlayerRadius = 25;
		const float mDefautlPlayerRadius = 250;
		const float mDefaultBorderManagementRadius = 5;
		Role role;
		std::string mName;
		float mSpeed;
		ezgame::Circle mPlayerShape;
		size_t mHitScore;
		float mTimeAsDefender;
		float mTimeAsContender;
		BorderManagement mBorderManagement;
		DirectionKeyMapping mDirectionKeyMapping;

	public:
		Player(Role role, std::string& name, ezgame::Color& color, DirectionKeyMapping& directionKeyMapping);

		Role role();

		std::string name();

		float speed();






};

