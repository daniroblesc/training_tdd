namespace Tennis
{
    public class TennisGame2 : ITennisGame
    {
        private const int POINT_LOVE = 0;
        private const int POINT_FIFTEEN = 1;
        private const int POINT_THIRTY = 2;
        private const int POINT_FORTY = 3;

        private const string SCORE_LOVE = "Love";
        private const string SCORE_FIFTEEN = "Fifteen";
        private const string SCORE_THIRTY = "Thirty";
        private const string SCORE_DEUCE = "Deuce";
        private const string SCORE_FORTY = "Forty";
        private const string SCORE_SEPARATOR = "-";
        private const string SCORE_WIN_PLAYER1 = "Win for player1";
        private const string SCORE_WIN_PLAYER2 = "Win for player2";
        private const string SCORE_ADV_PLAYER1 = "Advantage player1";
        private const string SCORE_ADV_PLAYER2 = "Advantage player2";

        private const int MIN_POINTS_UP_TO_WIN = 2;

        private int playerOnePoint;
        private int playerTwoPoint;

        private string playerOneResult = "";
        private string playerTwoResult = "";

        private string playerOneName;
        private string playerTwoName;

        public TennisGame2(string playerOneName, string playerTwoName)
        {
            playerOnePoint = 0;

            this.playerOneName = playerOneName;
            this.playerTwoName = playerTwoName;
        }

        public string GetScore()
        {
            var score = "";
            if (IsGameInDraw())
            {
                if (playerOnePoint < POINT_FORTY)
                {
                    score = GetPlayerOneResult();
                    score += SCORE_SEPARATOR;
                    score += "All";
                }
                else
                {
                    score = SCORE_DEUCE;
                }

            }

            if (IsPlayerOneWinning())
            {
                if (playerTwoPoint >= POINT_FORTY)
                {
                    score = SCORE_ADV_PLAYER1;
                }
                else
                {
                    score = BuildPartialScore();
                }
            }

            if (IsPlayerTwoWinning())
            {
                if (playerOnePoint >= POINT_FORTY)
                {
                    score = SCORE_ADV_PLAYER2;
                }
                else
                {
                    score = BuildPartialScore();
                }
            }

            if (IsPlayerOneInDeuce() && IsPlayerOneEnoughPointsUpToWin())
            {
                score = SCORE_WIN_PLAYER1;
            }

            if (IsPlayerTwoInDeuce() && IsPlayerTwoEnoughPointsUpToWin())
            {
                score = SCORE_WIN_PLAYER2;
            }
            return score;
        }

        private bool IsPlayerTwoEnoughPointsUpToWin()
        {
            return (playerTwoPoint - playerOnePoint) >= MIN_POINTS_UP_TO_WIN;
        }

        private bool IsPlayerOneEnoughPointsUpToWin()
        {
            return (playerOnePoint - playerTwoPoint) >= MIN_POINTS_UP_TO_WIN;
        }

        private bool IsPlayerTwoInDeuce()
        {
            return playerTwoPoint > POINT_FORTY;
        }

        private bool IsPlayerOneInDeuce()
        {
            return playerOnePoint > POINT_FORTY;
        }

        private string BuildPartialScore()
        {
            string score;
            playerOneResult = GetPlayerOneResult();
            playerTwoResult = GetPlayerTwoResult();

            score = playerOneResult + SCORE_SEPARATOR + playerTwoResult;
            return score;
        }

        private string GetPlayerOneResult()
        {
            var score = "";

            if (playerOnePoint == POINT_LOVE)
                score = SCORE_LOVE;
            if (playerOnePoint == POINT_FIFTEEN)
                score = SCORE_FIFTEEN;
            if (playerOnePoint == POINT_THIRTY)
                score = SCORE_THIRTY;
            if (playerOnePoint == POINT_FORTY)
                score = SCORE_FORTY;

            return score;
        }

        private string GetPlayerTwoResult()
        {
            var score = "";

            if (playerTwoPoint == POINT_LOVE)
                score = SCORE_LOVE;
            if (playerTwoPoint == POINT_FIFTEEN)
                score = SCORE_FIFTEEN;
            if (playerTwoPoint == POINT_THIRTY)
                score = SCORE_THIRTY;
            if (playerTwoPoint == POINT_FORTY)
                score = SCORE_FORTY;

            return score;
        }

        private bool IsPlayerTwoWinning()
        {
            return playerTwoPoint > playerOnePoint;
        }

        private bool IsPlayerOneWinning()
        {
            return playerOnePoint > playerTwoPoint;
        }

        private bool IsGameInDraw()
        {
            return playerOnePoint == playerTwoPoint;
        }

        private void P1Score()
        {
            playerOnePoint++;
        }

        private void P2Score()
        {
            playerTwoPoint++;
        }

        public void WonPoint(string player)
        {
            if (player == "player1")
                P1Score();
            else
                P2Score();
        }

    }
}

