#include "position.h"

Position::Position()
{
	Position::xy[0] = 0;
	Position::xy[1] = 0;
}

Position::Position(int x, int y)
{
	Position::xy[0] = x;
	Position::xy[1] = y;
}

/*Position::Position(int xy[2])
{
	Position::xy[0] = xy[0];
	Position::xy[1] = xy[1];
}*/

Position::~Position()
{
}

int Position::getX() {
	return Position::xy[0];
}

int Position::getY() {
	return Position::xy[1];
}

void Position::setX(int x) {
	Position::xy[0] = x;
}

void Position::setY(int y) {
	Position::xy[1] = y;
}

int * Position::getArray() {
	return Position::xy;
}

std::string Position::toString() {
	std::string str = std::to_string(Position::xy[0]) + ", " + std::to_string(Position::xy[1]);
	return str;
}