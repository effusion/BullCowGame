#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_length,
	Not_Lowercase,
};

class FBullCowGame {
public:
	FBullCowGame();
	void Reset(); // TODO make a more rich return value.
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWorldLength() const;

	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;// TODO make a more rich return value
	// provide a method for counting bulls & cows, and increase turn #
	FBullCowCount SubmitValidGuess(FString);
private:
	int32 MyMaxTries;
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameWon;

	bool IsIsogram(FString) const;
};
