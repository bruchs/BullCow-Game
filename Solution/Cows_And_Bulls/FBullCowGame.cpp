#include <iostream>
#include "FBullCowGame.h"
#include <map>
#define TMap std::map	

FBullCowGame::FBullCowGame()
{
	Restart();
}

void FBullCowGame::Restart()
{
	SetCurrenTry(1);
	mMaxTries = 10;
}

int32 FBullCowGame::GetCurrentTry() const { return FBullCowGame::mCurrentTry; }

int32 FBullCowGame::GetMaxTries() const { return FBullCowGame::mMaxTries; }

FString FBullCowGame::GetHiddenWord() const { return FBullCowGame::mHiddenWord; }

int32 FBullCowGame::GetHiddenWordLength() const { return FBullCowGame::mHiddenWord.length(); }

void FBullCowGame::SetMaxTries(int32 maxTries) { FBullCowGame::mMaxTries = maxTries; }

void FBullCowGame::SetCurrenTry(int32 currentTry) { FBullCowGame::mCurrentTry = currentTry; }

bool FBullCowGame::IsGameWon(FString currentGuess) const
{
	if (currentGuess == FBullCowGame::mHiddenWord)
		return true;
	else
		return false;
}

EGuessStatus FBullCowGame::CheckGuess(FString currentGuess) const
{
	if(IsIsogram(currentGuess))
	{
		if (currentGuess.length() != FBullCowGame::mHiddenWord.length())
		{
			std::cout << "Please Enter A Guess With " << FBullCowGame::mHiddenWord.length();
			std::cout << " Letters." << std::endl;
			return EGuessStatus::wrongLenght;
		}
		return EGuessStatus::isIsogram;
	}
}

// Receives a valid guess, increment the turn number, and return count.
FBullCowCount FBullCowGame::SubmitGuess(FString currentGuess) 
{
	FBullCowGame::mCurrentTry++;
	FBullCowCount currentBullCowCount;

	for(size_t i = 0; i < currentGuess.length(); i++)
	{
		for(size_t j = 0; j < FBullCowGame::mHiddenWord.length(); j++)
		{
			if (currentGuess[i] == FBullCowGame::mHiddenWord[j])
			{
				if(i == j)
				{
					currentBullCowCount.bullCount++;
				}
				else
				{
					currentBullCowCount.cowCount++;
				}
			}
		}
	}

	return currentBullCowCount;
}

bool FBullCowGame::IsIsogram(FString currentGuess) const
{
	if(currentGuess.length() <= 1) { return true; }

	TMap <char, bool> LetterSeen;

	for(char Letter	: currentGuess )
	{
		Letter = tolower(Letter);
		if(LetterSeen[Letter])
		{	
			std::cout << "Please Enter A Guess Without Repeating Letters" << std::endl;
			return false;
		}	
		else
			LetterSeen[Letter] = true;
	}
	return true;
}