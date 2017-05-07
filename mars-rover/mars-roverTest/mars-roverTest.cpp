// mars-roverTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "mars-rover.h"

// You are given the initial starting point (x,y) of a rover and the direction
// (N,S,E,W) it is facing.

TEST(testMarsRover, initialSetup)
{
	Point startingPoint;
	Direction startingDirectionToTheNorth(1, 0, 0, 0);
	
	MarsRover theRover(startingPoint, startingDirectionToTheNorth);

	bool result = (theRover.getStartingPoint() == startingPoint);
	EXPECT_EQ(result, true);

	result = (theRover.getStartingDirection() == startingDirectionToTheNorth);
	EXPECT_EQ(result, true);
}
