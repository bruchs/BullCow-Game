#pragma once
#include <iostream>
using FString = std::string;

void IntroduceGame();
FString GetGuess();
void PlayGame();
bool IsPlayingAgain(FString guess);
void GameSummary(FString guess);