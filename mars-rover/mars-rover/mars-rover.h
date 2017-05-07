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

	typedef enum
	{
		NORTH,
		SOUTH,
		EAST,
		WEST
	} CardinalPoints;

	Direction()
	{
		initialize();

		cardinals[NORTH] = true;
	}

	Direction(const bool N, const bool S, const bool E, const bool W)
	{
		initialize();

		cardinals[NORTH] = N;
		cardinals[SOUTH] = S;
		cardinals[EAST] = E;
		cardinals[WEST] = W;
	}

	Direction(const CardinalPoints direction)
	{
		initialize();

		cardinals[direction] = true;
	}

	Direction& operator= (const Direction &other)
	{
		this->cardinals = other.cardinals;

		return *this;
	}

	bool operator==(Direction& rhs)const
	{
		return (this->cardinals == rhs.cardinals);
	}

	bool isNorth()
	{
		return (this->cardinals[NORTH] && 
			!this->cardinals[SOUTH] && 
			!this->cardinals[EAST] && 
			!this->cardinals[WEST]);
	}

	

	void setDirection(const CardinalPoints newDirection)
	{
		reset();

		cardinals[newDirection] = true;
	}


private:

	std::map<CardinalPoints, bool> cardinals;

	void reset()
	{
		std::map<CardinalPoints, bool>::iterator it;
		it = cardinals.begin();

		while (it != cardinals.end())
		{
			it->second = false;
			++it;
		}
	}

	void initialize()
	{
		cardinals.clear();
		cardinals.insert(std::make_pair(NORTH, false));
		cardinals.insert(std::make_pair(SOUTH, false));
		cardinals.insert(std::make_pair(EAST, false));
		cardinals.insert(std::make_pair(WEST, false));
	}
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
				currentDirection.setDirection(Direction::WEST);
				result = true;
			}
		}
		else if (command == 'r')
		{
			if (currentDirection.isNorth())
			{
				currentDirection.setDirection(Direction::EAST);
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
