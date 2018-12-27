#pragma once
#include <string>

using FText = std::string;
using int32 = int;

// all variables set to 0
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class ECheckInput 
{
	No_Status,
	OK,
	Not_Isogram,
	Non_English_Char,
	Wrong_Length,
	No_Lowercase,
	
};
class FBullCowGame {
	
public:
	FBullCowGame();
	void Reset();
	ECheckInput CheckGuessValidity(FText Guess) const;
	int32 GetMaxTries() const;
	int32 GetHiddenWordLength() const;
	int32 GetCurrentTry() const;
	FBullCowCount SubmitValidGuess(FText);
	bool IsGameWon()const;
	bool IsLowerCase(FText Word)const;

// *See constructor for initialisation*
private:
	int32 MAX_TRIES = 8;
	bool IsIsogram(FText Word) const;
	int32 MyMaxTries = MAX_TRIES;
	int32 MyCurrentTry;
	FText MyHiddenWord;
	bool bIsGameWon;
};