#include "player.h"

Player::Player(std::string name)
{
	Player::name = name;
	Player::pos = Position();
	Player::facing = util::CARDINAL::NORTH;
}

Player::Player(std::string name, Position pos, util::CARDINAL facing)
{
	Player::name = name;
	Player::pos = pos;
	Player::facing = facing;
}

Player::~Player()
{
}

std::string Player::getName() {
	return Player::name;
}

Position Player::getPos() {
	return Player::pos;
}

void Player::setPos(Position pos) {
	Player::pos = pos;
}

util::CARDINAL Player::getFacing() {
	return Player::facing;
}

void Player::setFacing(util::CARDINAL facing) {
	Player::facing = facing;
}

void Player::move(int feet, Player::DIRECTION direction) {
	facing = static_cast<util::CARDINAL>(util::mod(facing + static_cast<util::CARDINAL>(direction), 4));
	res::sendError(std::to_string(facing) + ", " + std::to_string(direction) + ", " + std::to_string(static_cast<util::CARDINAL>(direction)));
	if (facing == util::CARDINAL::NORTH) {
		pos.getArray()[1]+=feet;
		res::sendValid("You have faced North and walked " + std::to_string(feet) + " feet");
	}
	else if (facing == util::CARDINAL::EAST) {
		pos.getArray()[0] += feet;
		res::sendValid("You have faced East and walked " + std::to_string(feet) + " feet");
	}
	else if (facing == util::CARDINAL::SOUTH) {
		pos.getArray()[1] -= feet;
		res::sendValid("You have faced South and walked " + std::to_string(feet) + " feet");
	}
	else if (facing == util::CARDINAL::WEST) {
		pos.getArray()[0] -= feet;
		res::sendValid("You have faced West and walked " + std::to_string(feet) + " feet");
	}
	else {
		res::sendDefault("Invalid direction");
	}

}

void Player::move(int feet, util::CARDINAL cardinal) {
	facing = cardinal;
	if (facing == util::CARDINAL::NORTH) pos.getArray()[1]++;
	else if (facing == util::CARDINAL::EAST) pos.getArray()[0]++;
	else if (facing == util::CARDINAL::SOUTH) pos.getArray()[1]--;
	else if (facing == util::CARDINAL::WEST) pos.getArray()[0]--;
}

void Player::turnLeft() {
	res::sendDefault(std::to_string(facing));
	facing = static_cast<util::CARDINAL>(util::mod((facing - 1), 4));
	res::sendDefault(std::to_string(facing));
}

void Player::turnAround() {
	facing = static_cast<util::CARDINAL>(util::mod((facing + 2), 4));
	res::sendDefault(std::to_string(facing));
}

void Player::turnRight() {
	facing = static_cast<util::CARDINAL>(util::mod((facing + 1), 4));
	res::sendDefault(std::to_string(facing));
}

