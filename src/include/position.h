#pragma once
#include <iostream>
#include <string>

class Position
{
public:
	Position();
	Position(int x, int y);
	//Position(int xy[2]);
	~Position();

	int getX();
	int getY();
	void setX(int x);
	void setY(int y);
	int * getArray();
	std::string toString();

private:
	int xy[2];
};