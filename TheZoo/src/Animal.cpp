/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This Is the abstract class Animal.cpp that all other animals classes are derived from and declares many of the programs variables
*/

//These are the three dependencies required in this file and using namespace std for ease
#include "../Header Files/Animal.h"
#include <string>
#include <iostream>
using namespace std;

//This is a empty default constructor, initially it was used but was more useful empty for this project and file reading without prompts
Animal::Animal() {
	
}
//This is the custom constructor that allows for universal prompts across all animal classes the bool parameter
//is only used for calling this constructor.
Animal::Animal(bool userEntry) {
	//Here a custom handling object of class "InputHandling is called to reuse code to the greatest extent possible
	//the GetUser String function accepts a string for prompt and returns a string, the Get user integer accepts a prompt
	//string, a max value and a min value. Both lines use Setters to assign values (to Animal name and trackingNumber
	SetAnimalName(handlingObj.GetUserString("Please Enter a Name: "));
	SetTrackingNumber(handlingObj.GetUserInteger("Please Enter RFID tracking number (6 digits or less): ", 1000000));

}
//This is a deconstructor, used early on it ended up only being needed for troubleshooting and bug catching
//It is now empty as there were no relevant features inside it.
Animal::~Animal() {
	
}

//This is two standard default setter functions, both could be in the header but for the project I chose to put them here.
void Animal::SetAnimalName(string name)
{
	animalName = name;
}

void Animal::SetTrackingNumber(int trackingNum)
{
	trackNumber = trackingNum;
}

//These are two Getter functions one for GetAnimalName that formats its spacing for easier file formating
//The Tracking number just returns an int Tracking number
string Animal::GetAnimalName()
{
	//This for loop is used to appropriately space and prepare animal Names for output to the user or a file
	//Relatively basic. Adds one space on the front and as many spaces as required on the back
	for (unsigned int i = animalName.size(); i < 15; i++) {
		if (animalName.at(0) != ' ') {
			animalName.insert(0, " ");
		}
		animalName.append(" ");
	}
	return animalName;
}

int Animal::GetTrackingNumber() const
{
	return trackNumber;
}
