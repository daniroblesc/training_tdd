#include <string>


class Player
{
public:

	Player(int score)
	{
		score_ = score;
	}

	int getPoints()
	{
		return score_;
	}


private:

	int score_;

};

class Game
{
public:

	Game(Player* playerOne, Player* playerTwo)
	{
		playerOne_ = playerOne;
		playerTwo_ = playerTwo;
	}

	std::string getScore()
	{

	}


private:

	Player* playerOne_;
	Player* playerTwo_;


};

const std::string tennis_score(int p1Score, int p2Score) {
	std::string score = "";
	std::string P1res = "";
	std::string P2res = "";

	Player playerOne(p1Score);
	Player playerTwo(p2Score);


	if (playerOne.getPoints() == playerTwo.getPoints() && playerOne.getPoints() < 4)
	{
		if (playerOne.getPoints() == 0)
			score = "Love";
		if (playerOne.getPoints() == 1)
			score = "Fifteen";
		if (playerOne.getPoints() == 2)
			score = "Thirty";
		score += "-All";
	}
	if (playerOne.getPoints() == playerTwo.getPoints() && playerOne.getPoints()>2)
		score = "Deuce";

	if (playerOne.getPoints() > 0 && playerTwo.getPoints() == 0)
	{
		if (playerOne.getPoints() == 1)
			P1res = "Fifteen";
		if (playerOne.getPoints() == 2)
			P1res = "Thirty";
		if (playerOne.getPoints() == 3)
			P1res = "Forty";

		P2res = "Love";
		score = P1res + "-" + P2res;
	}
	if (playerTwo.getPoints() > 0 && playerOne.getPoints() == 0)
	{
		if (playerTwo.getPoints() == 1)
			P2res = "Fifteen";
		if (playerTwo.getPoints() == 2)
			P2res = "Thirty";
		if (playerTwo.getPoints() == 3)
			P2res = "Forty";

		P1res = "Love";
		score = P1res + "-" + P2res;
	}

	if (playerOne.getPoints()>playerTwo.getPoints() && playerOne.getPoints() < 4)
	{
		if (playerOne.getPoints() == 2)
			P1res = "Thirty";
		if (playerOne.getPoints() == 3)
			P1res = "Forty";
		if (playerTwo.getPoints() == 1)
			P2res = "Fifteen";
		if (playerTwo.getPoints() == 2)
			P2res = "Thirty";
		score = P1res + "-" + P2res;
	}
	if (playerTwo.getPoints()>playerOne.getPoints() && playerTwo.getPoints() < 4)
	{
		if (playerTwo.getPoints() == 2)
			P2res = "Thirty";
		if (playerTwo.getPoints() == 3)
			P2res = "Forty";
		if (playerOne.getPoints() == 1)
			P1res = "Fifteen";
		if (playerOne.getPoints() == 2)
			P1res = "Thirty";
		score = P1res + "-" + P2res;
	}

	if (playerOne.getPoints() > playerTwo.getPoints() && playerTwo.getPoints() >= 3)
	{
		score = "Advantage player1";
	}

	if (playerTwo.getPoints() > playerOne.getPoints() && playerOne.getPoints() >= 3)
	{
		score = "Advantage player2";
	}

	if (playerOne.getPoints() >= 4 && playerTwo.getPoints() >= 0 && (playerOne.getPoints() - playerTwo.getPoints()) >= 2)
	{
		score = "Win for player1";
	}
	if (playerTwo.getPoints() >= 4 && playerOne.getPoints() >= 0 && (playerTwo.getPoints() - playerOne.getPoints()) >= 2)
	{
		score = "Win for player2";
	}
	return score;

}
