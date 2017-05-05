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
                    if (playerOnePoint == POINT_LOVE)
                        score = SCORE_LOVE;
                    if (playerOnePoint == POINT_FIFTEEN)
                        score = SCORE_FIFTEEN;
                    if (playerOnePoint == POINT_THIRTY)
                        score = SCORE_THIRTY;

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
                    score = "Advantage player1";
                }
                else
                {
                    if (playerOnePoint == POINT_FIFTEEN)
                        playerOneResult = SCORE_FIFTEEN;
                    if (playerOnePoint == POINT_THIRTY)
                        playerOneResult = SCORE_THIRTY;
                    if (playerOnePoint == POINT_FORTY)
                        playerOneResult = SCORE_FORTY;

                    if (playerTwoPoint == POINT_LOVE)
                        playerTwoResult = SCORE_LOVE;
                    if (playerTwoPoint == POINT_FIFTEEN)
                        playerTwoResult = SCORE_FIFTEEN;
                    if (playerTwoPoint == POINT_THIRTY)
                        playerTwoResult = SCORE_THIRTY;

                    score = playerOneResult + SCORE_SEPARATOR + playerTwoResult;
                }               
            }

            if (IsPlayerTwoWinning())
            {
                if (playerOnePoint >= POINT_FORTY)
                {
                    score = "Advantage player2";
                }
                else
                {
                    if (playerTwoPoint == POINT_FIFTEEN)
                        playerTwoResult = SCORE_FIFTEEN;
                    if (playerTwoPoint == POINT_THIRTY)
                        playerTwoResult = SCORE_THIRTY;
                    if (playerTwoPoint == POINT_FORTY)
                        playerTwoResult = SCORE_FORTY;

                    if (playerOnePoint == POINT_LOVE)
                        playerOneResult = SCORE_LOVE;
                    if (playerOnePoint == POINT_FIFTEEN)
                        playerOneResult = SCORE_FIFTEEN;
                    if (playerOnePoint == POINT_THIRTY)
                        playerOneResult = SCORE_THIRTY;

                    score = playerOneResult + SCORE_SEPARATOR + playerTwoResult;
                }
            }

            if (playerOnePoint >= 4 && playerTwoPoint >= 0 && (playerOnePoint - playerTwoPoint) >= 2)
            {
                score = "Win for player1";
            }
            if (playerTwoPoint >= 4 && playerOnePoint >= 0 && (playerTwoPoint - playerOnePoint) >= 2)
            {
                score = "Win for player2";
            }
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

