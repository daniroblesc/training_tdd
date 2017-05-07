// mars-roverTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "mars-rover.h"

namespace 
{

// The fixture for testing class MarsRover.
class MarsRoverTest : public ::testing::Test 
{
protected:
	Point startingPoint;
	Direction startingDirection;
	MarsRover* theRover;


	MarsRoverTest() {
		// You can do set-up work for each test here.

		Direction startingDirectionToTheNorth(1, 0, 0, 0);
		startingDirection = startingDirectionToTheNorth;

		theRover = new MarsRover(startingPoint, startingDirection);
	}

	virtual ~MarsRoverTest() {
		// You can do clean-up work that doesn't throw exceptions here.
		delete theRover;
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:

	virtual void SetUp() {
		// Code here will be called immediately after the constructor (right
		// before each test).
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}
};


// You are given the initial starting point (x,y) of a rover and the direction
// (N,S,E,W) it is facing.

TEST_F(MarsRoverTest, initialSetup)
{
	bool result = (theRover->getStartingPoint() == startingPoint);
	EXPECT_EQ(result, true);

	result = (theRover->getStartingDirection() == startingDirection);
	EXPECT_EQ(result, true);
}



}  // namespace