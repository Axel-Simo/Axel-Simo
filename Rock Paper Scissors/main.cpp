/*
Created: 26/06/2024

Author: Simo Axel

Description: This program is a rock, paper, scissors game.

To compile: g++ main.cpp functionfile.cpp -o main

All functions take values by reference and return void because the modify
the values passed to them through constant pointers so that any modifications can be seen
in the main function and eventually shared with the other functions.

*/
#include <iostream>
#include "functionfile.h"

int main() {

  char userWantsToPlay = 'n';
  unsigned int numberOfRounds = 0;
  int computerWins = 0;
  int playerWins = 0;
  int playerMove = -1;

  std::string computerMove = "";
  std::string playerMoveName = "";

  gameInitialization(&userWantsToPlay, &numberOfRounds, START_GAME);

  while((userWantsToPlay == 'Y' || userWantsToPlay == 'y') && numberOfRounds > 0) {

    playersPickTheirMove(&computerMove, &playerMoveName, &playerMove);

    switch (playerMove)
    {
    case 0: //rock
      userPlaysRock(&numberOfRounds, playerMoveName, computerMove, &playerWins, &computerWins);
      break;

    case 1: //paper
      userPlaysPaper(&numberOfRounds, playerMoveName, computerMove, &playerWins, &computerWins);
      break;
    
    case 2: //scissors
      userPlaysScissors(&numberOfRounds, playerMoveName, computerMove, &playerWins, &computerWins);
      break;

    default:
      std::cout << "Invalid move" << std::endl;
      break;
    }

    if(numberOfRounds == 0) {

      winnerDeclarator(playerWins, computerWins);
      gameInitialization(&userWantsToPlay, &numberOfRounds, PLAY_AGAIN);

    }
    
  }

  std::cout << "Goodbye!\nThanks for playing our game :)" << std::endl;
  
  return 0;
}