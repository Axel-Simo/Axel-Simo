#include <iostream>

void gameInitialization(char * const userWantsToPlay, unsigned int * const numberOfRounds, std::string message) {

  std::cout << message << "\n'Y' or 'y' to start, any other character to stop." << std::endl;
  std::cin >> userWantsToPlay;

  if(*userWantsToPlay == 'Y' || *userWantsToPlay == 'y') {
    std::cout << "Best of how many?(can't be greater than 5)" << std::endl;
    std::cin >> *numberOfRounds;
    *numberOfRounds = *numberOfRounds % 5;

    std::cout << "We will be playing " << *numberOfRounds << " rounds." << std::endl;
  }
  
}

void playersPickTheirMove(std::string * const computerMove, std::string * const playerMoveName, int * const playerMove) {

  int randNumber = rand() % 3;
  *computerMove = (randNumber == 0) ? "rock" : (randNumber == 1) ? "paper" : "scissors";
  std::cout << " Computer move picked. Pick a number between 0 and 2\n(0 = rock, 1 = paper, 2 = scissors):" << std::endl;

  std::cin >> *playerMove;

  *playerMoveName = (*playerMove == 0) ? "rock" : (*playerMove == 1) ? "paper" : "scissors";

}

void userPlaysRock(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins) {
  
  *numberOfRounds -= 1;
  
  if(playerMoveName == computerMove) { std::cout << "Draw" << std::endl; }

  else if(computerMove == "paper") { std::cout << "Computer wins" << std::endl; *computerWins += 1; }

  else { std::cout << "Player wins" << std::endl; *playerWins += 1; }

}

void userPlaysPaper(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins) {
  
  *numberOfRounds -= 1;
  
  if(playerMoveName == computerMove) { std::cout << "Draw" << std::endl; }
  
  else if(computerMove == "scissors") { std::cout << "Computer wins" << std::endl; *computerWins += 1; }
  
  else { std::cout << "Player wins" << std::endl; *playerWins += 1; }

}

void userPlaysScissors(unsigned int * const numberOfRounds, std::string playerMoveName, std::string computerMove, int * const playerWins, int * const computerWins) {

  *numberOfRounds -= 1;
  
  if(playerMoveName == computerMove) { std::cout << "Draw" << std::endl; }
  
  else if(computerMove == "rock") { std::cout << "Computer wins" << std::endl; *computerWins += 1; }
  
  else { std::cout << "Player wins" << std::endl; *playerWins += 1; }

}

void winnerDeclarator(int playerWins, int computerWins) {
      if(computerWins == playerWins) {
      std::cout << "Game is a draw" << std::endl;
    }

    if(computerWins > playerWins) {
      std::cout << "Compute wins the game" << std::endl;
    }

    if(computerWins < playerWins) {
      std::cout << "Player wins the game" << std::endl;
    }
}