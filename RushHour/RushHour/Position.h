#ifndef POSITION_H
#define POSITION_H

class Position
{
public:
	Position(int x, int y) : x(x), y(y) {};
	~Position() {};
	int getX() const { return x; }
	int getY() const { return y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

private:
	int x;
	int y;
};

#endif