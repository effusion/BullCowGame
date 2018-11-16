#include "FBullCowGame.h"
#include  <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{	
	constexpr int MAX_TRIES = 3;
	const FString HIDDEN_WORD = "planet";
	bGameWon = false;

	MyCurrentTry = 1;
	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	TMap<char, bool> isogramCheck;
	//Fill with the alphabet
}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{	
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWorldLength() const { return MyHiddenWord.length(); }

bool FBullCowGame::IsGameWon() const { return bGameWon; }

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if(!IsIsogram(Guess)){
		return EGuessStatus::Not_Isogram;
	} else if(false){ //TODO  Right is all lower case
		return EGuessStatus::Not_Lowercase;
	} else if(GetHiddenWorldLength() != Guess.length()){
		return EGuessStatus::Wrong_length;
	} else {
		return EGuessStatus::OK;
	}
}

// receives a valid guess, increments turn, and return counts.
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{	

	MyCurrentTry++;
	FBullCowCount BullCowCount;
	// loop through all letters in the hidden word
	const int32 WordLength = MyHiddenWord.length();
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the hidden word
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			if (Guess[GChar] == MyHiddenWord[MHWChar]){
				if (MHWChar == GChar) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if(BullCowCount.Bulls == GetHiddenWorldLength()){
		bGameWon = true;
	}else{
		bGameWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{	
	if(Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word)	{	
		Letter = tolower(Letter);
		if(!LetterSeen[Letter]){
			LetterSeen[Letter] = true;
		}else{
			return false;
		}
	
	}
	return true;
}

