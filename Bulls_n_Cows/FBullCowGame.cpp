#include "FBullCowGame.h"
#include <iostream>
#include <string>
#include <map>
#define TMap = std::map;
using FText = std::string;
using int32 = int;

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

int32 FBullCowGame::GetMaxTries() const {
	
	
	
	return MyMaxTries; }

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}


FBullCowGame::FBullCowGame() { Reset(); } // default constructor



bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

bool FBullCowGame::IsLowerCase(FText Word) const
{
	if (Word.length() <= 1) { return true; }
	for (auto Letter : Word) {

		if (!islower(Letter)) { return false; }
		else { return true; }
	}
}

bool FBullCowGame::IsIsogram(FText Word) const
{
	if (Word.length() <= 1) { return true; }
	std::map <char, bool> LetterSeen;
	for (auto Letter : Word){
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) { return false; }
		else { LetterSeen[Letter] = true; }
	}
}

void FBullCowGame::Reset() { 

	bIsGameWon = false;
	const FText HIDDEN_WORD = "fuckery";
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	return; }


ECheckInput FBullCowGame::CheckGuessValidity(FText Guess) const
{
	// if the guess isn't an isogram => return an error
	if (!IsIsogram(Guess)) {
		return ECheckInput::Not_Isogram;
	}
	// if the guess isn't all lowercase => return an error
	else if (!IsLowerCase(Guess)) {
		return ECheckInput::No_Lowercase;
		}
	// if the guess length is wrong => return an error
	else if (Guess.length() != MyHiddenWord.length()) {
		return ECheckInput::Wrong_Length;
	}
	// otherwise => return OK
	else {
		return ECheckInput::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FText Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length(); // assuming same length as guess

	// loop through all letters in the hidden word
	for (int32 MHWChar = 0; MHWChar < WordLength; MHWChar++) {
		// compare letters against the guess
		for (int32 GChar = 0; GChar < WordLength; GChar++) {
			// if they match then
			if (Guess[GChar] == MyHiddenWord[MHWChar]) {
				if (MHWChar == GChar) { // if they're in the same place
					BullCowCount.Bulls++; // incriment bulls
				}
				else {
					BullCowCount.Cows++; // must be a cow
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bIsGameWon = true;
	}
	else
	{
		bIsGameWon = false;
	}
	return BullCowCount;
}