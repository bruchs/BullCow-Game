#include <iostream>
#include <locale>
#include <string>
#include "main.h"
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int32;

bool isPlaying;
FBullCowGame currentGame;

int main() 
{
	PlayGame();
	return 0;
}

void IntroduceGame()
{
	std::cout << "Welcome To Cows and Bulls" << std::endl;
	std::cout << "Can You Guess The " << currentGame.GetHiddenWordLength() << " Letter Isogram I'm Thinking Of?" << std::endl;
	std::cout << std::endl;
}

FText GetGuess()
{
	std::cout << "Current Try: " << currentGame.GetCurrentTry() << ". Please Enter Your Guess" << std::endl;
	FText playerGuess = "";
	std::getline(std::cin, playerGuess);
	
	return playerGuess;
}

void PlayGame()
{
	FString currentGuess;
	int32 maxTries = currentGame.GetHiddenWordLength();
	isPlaying = true;

	do
	{
		IntroduceGame();

		for (size_t i = 0; i < maxTries; i++)
		{
			currentGuess = GetGuess();
			std::locale loc;
			FString tempResult;

			// Set our guess string to be lowercase.
			for (size_t j = 0; j < currentGuess.length(); j++)
			{
				FString currentChar = "";
				currentChar = tolower(currentGuess[j]);
				tempResult.append(currentChar);
			}

			currentGuess = tempResult;

			// We check the validity of our current guess.
			EGuessStatus guessStatus = currentGame.CheckGuess(currentGuess);

			if (guessStatus == isIsogram)
			{
				std::cout << "The Player Guess Is: " << currentGuess << std::endl;

				// Submit valid guess to the game, and recieve the results.
				FBullCowCount currentCount = currentGame.SubmitGuess(currentGuess);
				std::cout << "The Number Of Bulls Is: " << currentCount.bullCount << std::endl;
				std::cout << "The Number Of Cows Is: " << currentCount.cowCount << std::endl;
				std::cout << std::endl;

				if (currentGame.IsGameWon(currentGuess) || currentGame.GetCurrentTry() == maxTries)
				{
					if (!IsPlayingAgain(currentGuess))
						break;
				}	
			}
			else
				--i;
		}
	} while (isPlaying);
}

void GameSummary(FString currentGuess)
{
	if(currentGame.IsGameWon(currentGuess))
	{
		std::cout << "YOU WIN!, THE GUESS WAS: " + currentGame.GetHiddenWord() << std::endl;
	}
	else
	{
		std::cout << "YOU LOSE!, GOOD LUCK NEXT TIME" << std::endl;
	}
}

bool IsPlayingAgain(FString currentGuess)
{
	GameSummary(currentGuess);
	std::cout << "Do You Want To Play Again?" << std::endl;
	std::cout << "Select 'Y/N'" << std::endl;
	FText playerDecision = "";
	std::getline(std::cin, playerDecision);

	std::locale loc;
	playerDecision = toupper(playerDecision[0], loc);

	if (playerDecision == "Y")
	{
		IntroduceGame();
		currentGame.Restart();
		return true;
	}
	else if (playerDecision == "N")
	{
		isPlaying = false;
		return false;
	}
	else
	{
		std::cout << "Incorrect Awnser" << std::endl;
		IsPlayingAgain(currentGuess);
	}
}