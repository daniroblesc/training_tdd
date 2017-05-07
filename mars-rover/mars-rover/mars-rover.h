#pragma once

class Point
{
public:
	Point()
	{
		this->x = 0;
		this->y = 0;
	}

	Point(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}
	
	Point& operator= (const Point &other)
	{
		this->x = other.x;
		this->y = other.y;

		return *this;
	}

	bool operator==(Point& rhs)const
	{
		return ((this->x == rhs.x) && (this->y == rhs.y));
	}


private:

	int x;
	int y;
};

class Direction
{
public:
	Direction()
	{
		this->N = 0;
		this->S = 0;
		this->E = 0;
		this->W = 0;
	}

	Direction(const int N, const int S, const int E, const int W)
	{
		this->N = N;
		this->S = S;
		this->E = E;
		this->W = W;
	}


	Direction& operator= (const Direction &other)
	{
		this->N = other.N;
		this->S = other.S;
		this->E = other.E;
		this->W = other.W;

		return *this;
	}

	bool operator==(Direction& rhs)const
	{
		return ((this->N == rhs.N) &&
				(this->S == rhs.S) &&
				(this->E == rhs.E) &&
				(this->W == rhs.W));
	}


private:
	int N;
	int S;
	int E;
	int W;
};

class MarsRover
{
public:
	MarsRover(const Point& startingPoint, const Direction& startingDirection)
	{
		this->currentPoint = startingPoint;
		this->currentDirection = startingDirection;
	}


	Point& getPoint()
	{
		return currentPoint;
	}

	Direction& getDirection()
	{
		return currentDirection;
	}

	bool SendCommands(std::vector<char>& commands)
	{
		this->commands = commands;
		return true;
	}


private:

	Point currentPoint;
	Direction currentDirection;
	std::vector<char> commands;
};
