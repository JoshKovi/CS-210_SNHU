/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the crocodile child class, they are all roughly the same
*/


#pragma once

#include <string>
#include "InputHandling.h"
using namespace std;

class InputHandling {

public:

	//All three functions are declared here and defined in the .cpp file, all are public as all classes utilize them to some extent
	char GetFirstChar(string inputPrompt);
	string GetUserString(string inputPrompt);
	int GetUserInteger(string inputPrompt, int maxLimit, int minLimit = 0);

};
