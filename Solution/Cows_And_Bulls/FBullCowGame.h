#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 bullCount = 0;
	int32 cowCount = 0;
};

enum EGuessStatus
{
	isIsogram,
	notIsogram,
	wrongLenght,
};

class FBullCowGame
{
public:
	FBullCowGame();

	int32 GetCurrentTry() const;
	int32 GetMaxTries() const;
	FString GetHiddenWord() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon(FString currentGuess) const;
	EGuessStatus CheckGuess(FString currentGuess) const;

	void Restart();
	void SetMaxTries(int32 maxTries);
	void SetCurrenTry(int32 currentTrys);
	FBullCowCount SubmitGuess(FString currentGuess);

private:
	int32 mCurrentTry;
	int32 mMaxTries = 5;
	FString mHiddenWord = "planet";

	bool IsIsogram(FString currentGuess) const;
};
