#pragma once
#include <EzGame>
#include "StandardMapping.h"
#include "Direction.h"


class DirectionKeyMapping
{
	private:
		ezgame::Keyboard::Key mLeftKeyMapping;
		ezgame::Keyboard::Key mRightKeyMapping;
		ezgame::Keyboard::Key mUpKeyMapping;
		ezgame::Keyboard::Key mDowntKeyMapping;
	public:
		DirectionKeyMapping(StandardMapping standardMapping);

		ezgame::Keyboard::Key keyMapping(Direction direction);

		ezgame::Vect2d directionFromKeybord(ezgame::Keyboard& keyboard);

		void setKeyMapping(Direction direction, ezgame::Keyboard::Key key);

		void setKeyMapping(ezgame::Keyboard::Key leftKey, ezgame::Keyboard::Key upKey, ezgame::Keyboard::Key rightKey, ezgame::Keyboard::Key downKey);

		void setKeyMapping(StandardMapping standardMapping);

};

