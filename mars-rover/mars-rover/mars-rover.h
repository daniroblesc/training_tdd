#pragma once

#include <queue>

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

	void incY()
	{
		y++;
	}

	void decY()
	{
		y--;
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
		this->N = true;
		this->S = false;
		this->E = false;
		this->W = false;
	}

	Direction(const bool N, const bool S, const bool E, const bool W)
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

	bool isNorth()
	{
		return (N && !S && !E && !W);
	}

	void setWest()
	{
		N = false;
		S = false;
		E = false;
		W = true;
	}


private:
	bool N;
	bool S;
	bool E;
	bool W;
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

	bool SendCommands(std::queue<char>& commands)
	{
		this->commands = commands;
		return true;
	}

	bool ExecuteCommand()
	{
		bool result = false;

		char command = commands.front();
		commands.pop();

		if (command == 'f')
		{
			if (currentDirection.isNorth())
			{
				currentPoint.incY();
				result = true;
			}
		}
		else if (command == 'b')
		{
			if (currentDirection.isNorth())
			{
				currentPoint.decY();
				result = true;
			}
		}
		else if (command == 'l')
		{
			if (currentDirection.isNorth())
			{
				currentDirection.setWest();
				result = true;
			}
		}


		return result;
	}


private:

	Point currentPoint;
	Direction currentDirection;
	std::queue<char> commands;
};
