#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FBullCowGame BCGame;

void PrintIntro() {
	std::cout << std::endl;
	std::cout << "\n\nWelcome to Bulls and Cows, a fun word game\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWorldLength();
	std::cout << " letter isogram I'm thinking of?\n\n";
}

FText GetValidGuess(){
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess;
	do {
		std::cout << "Try " << BCGame.GetCurrentTry() << ". ";
		std::cout << "Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_length:
			std::cout << "Please enter a " << BCGame.GetHiddenWorldLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			// assume the guess is valid
			break;
		}
		std::cout << std::endl;
	} while (EGuessStatus::OK !=Status);
	return Guess;
}


void PrintGameSummary()
{
	if(BCGame.IsGameWon())
	{
		std::cout << "You Won!\n\n";
	}else
	{
		std::cout << "Bad luck! Next time ;)\n\n";
	}
}


void PlayGame(){
	
	BCGame.Reset();

	const int32 MaxTries = BCGame.GetMaxTries();
	while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows =" << BullCowCount.Cows << "\n\n";
		std::cout << "Your guess was:" << Guess << std::endl << std::endl;
	}

	PrintGameSummary();
}

bool AskToPlayAgain(){
	std::cout << "Do you want to play again with the same word(y/n)? ";
	FText Response;
	std::getline(std::cin, Response);
	return Response[0] == 'Y' || Response[0] == 'y';
}

int main() {

	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain());

	return 0;
}