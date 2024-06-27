#include <iostream>

const std::string START_GAME = "Start game?";
const std::string PLAY_AGAIN = "Play again?";


void gameInitialization(char * const userWantsToPlay, unsigned int * const numberOfRounds, std::string message);

void playersPickTheirMove(std::string * const computerMove, std::string * const playerMoveName, int * const playerMove);

void userPlaysRock(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins);

void userPlaysPaper(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins);

void userPlaysScissors(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins);

void winnerDeclarator(int playerWins, int computerWins);