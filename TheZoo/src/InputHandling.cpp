/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the InputHandling.cpp file, by far the three most used functions of the entire program
*/

#pragma once

#include "../Header Files/InputHandling.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


//This takes a prompt and returns a char or reprompts for input
char InputHandling::GetFirstChar(string inputPrompt) {
	//This string is instantiated as empty for the while loop
	string inputString = "";
	//This cout prompts the user whatever the prompt string is
	cout << inputPrompt << endl;
	//This intakes the entire line of input and then attempts to extract the first character
	//out of the string, the while loop is used to prevent blank inputs leading to bugs
	getline(cin, inputString);
	while (inputString == "") {
		cout << inputPrompt << endl;
		getline(cin, inputString);
	}

	//Once a valid string has been recover the first char of that string is returned for user selection
	return inputString.at(0);
}
	
string InputHandling::GetUserString(string inputPrompt) {
	//This accepts a string and assigns and returns it, using a prompt string making the code
	//Reusable for most the program
	string inputString;
	cout << inputPrompt << endl;
	getline(cin, inputString);
	return inputString;
}

int InputHandling::GetUserInteger(string inputPrompt, int maxLimit, int min) {
	//This function gets user input integers and has a max and min parameter to set
	//acceptable limites accross different integer prompts

	//The input string is what allows user input to be checked before attempting assignment as returnInt
	string inputString;
	int returnInt;

	//This do/while loop prompts the user, accepts input, checks the input for a quit signal or a digit,
	//and reprompts the user until they quit or enter valid input
	do {
		cout << inputPrompt << endl;
		getline(cin, inputString);
		//This is the line checking if the string can be converted into an integer
		if (isdigit(inputString.at(0))) {
			//This line converts a string into an integer
			returnInt = stoi(inputString);

			//This ensures the int is in the expected range, prompts user if not
			if (returnInt >= maxLimit || returnInt < min) {
				cout << "Number can be no more than " << maxLimit << endl;
				cout << "and can be no less than " << min << endl;
				continue;
			}
			else {
				//returns in range int to caller
				return returnInt;
			}
		}
		//Allow for easy escape back tto main menu
		else {
			if (inputString.at(0) == 'q' || inputString.at(0) == 'Q') {
				return -1;
			}
			//Prompts user when invalid input i.e (not a number)
			cout << "Invalid input, please enter a number or press 'q' to quit. " << endl;
		}
		//uses q to break the loop
	} while (inputString.at(0) != 'q' || inputString.at(0) != 'Q');
}

