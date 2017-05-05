using System.Collections.Generic;

namespace Tennis
{
    class TennisGame1 : ITennisGame
    {
        private const string PLAYER_ONE = "player1";

        private const string LOVE_ALL = "Love-All";
        private const string FIFTEEN_ALL = "Fifteen-All";
        private const string THIRTY_ALL = "Thirty-All";
        private const string DEUCE = "Deuce";
        private const string ADVANTAGE1 = "Advantage player1";
        private const string ADVANTAGE2 = "Advantage player2";
        private const string WIN1 = "Win for player1";
        private const string WIN2 = "Win for player2";

        private const int SCORING_STEP = 1;

        private const int SCORE_NONE = 0;
        private const int SCORE_FIFTEEN = 1;
        private const int SCORE_THIRTY = 2;
        private const int SCORE_FORTY = 3;
        private const int SCORE_WIN = 4;

        private const int MIN_WIN_SCORE_DELTA = 2;

        class Player
        {
            public string name;
            public int points;
            public Dictionary<int, string> scores = new Dictionary<int, string>
            {
                {SCORE_NONE, "Love" },
                {SCORE_FIFTEEN, "Fifteen" },
                {SCORE_THIRTY, "Thirty" },
                {SCORE_FORTY, "Forty" }
            };
            
            public Player(string name)
            {
                this.name = name;
                points = SCORE_NONE;
            }

            public void WonPoint()
            {
                points += SCORING_STEP;
            }

            public bool IsInEndOfGameSituation()
            {
                return (points >= SCORE_WIN);
            }

            public string GetScore()
            {
                return scores[points];

            }
        }

        private Player playerOne;
        private Player playerTwo;


        public TennisGame1(string player1Name, string player2Name)
        {
            playerOne = new Player(player1Name);
            playerTwo = new Player(player2Name);
        }

        public void WonPoint(string playerName)
        {
            if (playerName == PLAYER_ONE)
            {
                playerOne.WonPoint();
            }
            else
            {
                playerTwo.WonPoint();
            }
        }

        public string GetScore()
        {
            string score = "";

            if (IsInDraw())
            {
                switch (playerOne.points)
                {
                    case SCORE_NONE:
                        score = LOVE_ALL;
                        break;
                    case SCORE_FIFTEEN:
                        score = FIFTEEN_ALL;
                        break;
                    case SCORE_THIRTY:
                        score = THIRTY_ALL;
                        break;
                    case SCORE_FORTY:
                    default:
                        score = DEUCE;
                        break;

                }
            }
            else if (IsInEndOfGameSituation())
            {
                var minusResult = playerOne.points - playerTwo.points;
                if (minusResult == SCORING_STEP) score = ADVANTAGE1;
                else if (minusResult == -SCORING_STEP) score = ADVANTAGE2;
                else if (minusResult >= MIN_WIN_SCORE_DELTA) score = WIN1;
                else score = WIN2;
            }
            else
            {
                score = BuildScore();
            }
            return score;
        }

        private string BuildScore()
        {
            string score = playerOne.GetScore();
            score += "-";
            score += playerTwo.GetScore();
            return score;
        }

        private bool IsInDraw()
        {
            return (playerOne.points == playerTwo.points);
        }

        private bool IsInEndOfGameSituation()
        {
            return (playerOne.IsInEndOfGameSituation() || playerTwo.IsInEndOfGameSituation());
        }
    }
}

