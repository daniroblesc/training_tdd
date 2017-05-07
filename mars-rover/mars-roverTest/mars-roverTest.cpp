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
	std::queue<char> commands;


	MarsRoverTest() {
		// You can do set-up work for each test here.
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
	bool result = (theRover->getPoint() == startingPoint);
	EXPECT_EQ(result, true);

	result = (theRover->getDirection() == startingDirection);
	EXPECT_EQ(result, true);
}

// The rover receives a character array of commands.
TEST_F(MarsRoverTest, receiveCommands)
{
	commands.push('a');
	commands.push('b');

	bool result = theRover->SendCommands(commands);

	EXPECT_EQ(result, true);
}

// Implement commands that move the rover forward/backward (f,b).
TEST_F(MarsRoverTest, GivenRoverInInitialPositionAndOrientedToNorth_WhenMoveForward_ThenYCoordIsIncremented)
{
	Point pointExpected(0, 1); // Initial position is (0,0) and initial direction 
							   // is North so a forward movement will increase Y 
							   // to 1

	commands.push('f');
	theRover->SendCommands(commands);
	bool commandSupported = theRover->ExecuteCommand();

	Point pointAfterCommand = theRover->getPoint();

	bool result = (pointExpected == pointAfterCommand);

	EXPECT_EQ(commandSupported, true);
	EXPECT_EQ(result, true);
}

TEST_F(MarsRoverTest, GivenRoverInInitialPositionAndOrientedToNorth_WhenMoveBackward_ThenYCoordIsDecremented)
{
	Point pointExpected(0, -1); // Initial position is (0,0) and initial direction 
							    // is North so a backward movement will decrease Y 
							    // to -1

	commands.push('b');
	theRover->SendCommands(commands);
	bool commandSupported = theRover->ExecuteCommand();

	Point pointAfterCommand = theRover->getPoint();

	bool result = (pointExpected == pointAfterCommand);

	EXPECT_EQ(commandSupported, true);
	EXPECT_EQ(result, true);
}

// Implement commands that turn the rover left / right(l, r).
TEST_F(MarsRoverTest, GivenRoverInInitialPositionAndOrientedToNorth_WhenMoveLeft_ThenDirectionIsWest)
{
	Direction directionExpected(false, false, false, true);

	commands.push('l');
	theRover->SendCommands(commands);
	bool commandSupported = theRover->ExecuteCommand();

	Direction directionAfterCommand = theRover->getDirection();

	bool result = (directionExpected == directionAfterCommand);

	EXPECT_EQ(commandSupported, true);
	EXPECT_EQ(result, true);
}

TEST_F(MarsRoverTest, GivenRoverInInitialPositionAndOrientedToNorth_WhenMoveRight_ThenDirectionIsEast)
{

}

}  // namespace