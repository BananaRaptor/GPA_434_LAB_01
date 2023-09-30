#include "DirectionKeyMapping.h"

DirectionKeyMapping::DirectionKeyMapping(StandardMapping standardMapping = StandardMapping::WASD)
{
	setKeyMapping(standardMapping);
}

ezgame::Keyboard::Key DirectionKeyMapping::keyMapping(Direction direction)
{
	switch (direction) {
	case Direction::Up:
		return mUpKeyMapping;

	case Direction::Down:
		return mDowntKeyMapping;

	case Direction::Left:
		return mLeftKeyMapping;

	case Direction::Right:
		return mRightKeyMapping;
	}
}

ezgame::Vect2d DirectionKeyMapping::directionFromKeyboard(const ezgame::Keyboard& keyboard)
{
	if (keyboard.isKeyPressed(mLeftKeyMapping)) {
		return ezgame::Vect2d::Vect2d(-1, 0);
	}
	if (keyboard.isKeyPressed(mRightKeyMapping)) {
		return ezgame::Vect2d::Vect2d(1, 0);
	}
	if (keyboard.isKeyPressed(mUpKeyMapping)) {
		return ezgame::Vect2d::Vect2d(0, -1);
	}
	if (keyboard.isKeyPressed(mDowntKeyMapping)) {
		return ezgame::Vect2d::Vect2d(0, 1);
	}
	return ezgame::Vect2d::Vect2d(0, 0);
}

void DirectionKeyMapping::setKeyMapping(Direction direction, ezgame::Keyboard::Key key)
{
	switch (direction) {
	case Direction::Up:
		mUpKeyMapping = key;
		break;

	case Direction::Down:
		mDowntKeyMapping = key;
		break;

	case Direction::Left:
		mLeftKeyMapping = key;
		break;

	case Direction::Right:
		mRightKeyMapping = key;
		break;

	default:
		return;
	}
	return;
}

void DirectionKeyMapping::setKeyMapping(ezgame::Keyboard::Key leftKey, ezgame::Keyboard::Key upKey, ezgame::Keyboard::Key rightKey, ezgame::Keyboard::Key downKey)
{
	mLeftKeyMapping = leftKey;
	mUpKeyMapping = upKey;
	mRightKeyMapping = rightKey;
	mDowntKeyMapping = downKey;


}

void DirectionKeyMapping::setKeyMapping(StandardMapping standardMapping)
{
	switch (standardMapping)
	{
	case StandardMapping::WASD:
		setKeyMapping(ezgame::Keyboard::Key::A, ezgame::Keyboard::Key::W, ezgame::Keyboard::Key::D, ezgame::Keyboard::Key::S);
		break;
	case StandardMapping::IJKL:
		setKeyMapping(ezgame::Keyboard::Key::J, ezgame::Keyboard::Key::I, ezgame::Keyboard::Key::L, ezgame::Keyboard::Key::K);
		break;
	case StandardMapping::Arrows:
		setKeyMapping(ezgame::Keyboard::Key::Left, ezgame::Keyboard::Key::Up, ezgame::Keyboard::Key::Right, ezgame::Keyboard::Key::Down);
		break;
	case StandardMapping::Num8426:
		setKeyMapping(ezgame::Keyboard::Key::Numpad4, ezgame::Keyboard::Key::Numpad2, ezgame::Keyboard::Key::Numpad6, ezgame::Keyboard::Key::Numpad8);
		break;
	default:
		break;
	}
}
