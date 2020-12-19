/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Oviparous class which is the child to animal and the parent to the three child classes Pelican, Crocodile and Goose
//Extremely similar to the Mammal cpp class
*/

#pragma once
#include "../Header Files/Oviparous.h"


//This is the default constructor that sets the default type "Oviparous" and nursing to 0
Oviparous::Oviparous()
{
	SetType();
	nursing = 0;
}

//This is used to call prompts for the user to assign values when they personally create a class it also calls the parent constructor class
Oviparous::Oviparous(bool userEntry) : Animal(userEntry)
{
	//Set type defaults to Oviparous, nursing to 0, then the Number of eggs setter is called prompting the user
	SetType();
	nursing = 0;
	SetNumberOfEggs();
}

//This and the getter below it are standard default getters and setters
void Oviparous::SetType()
{
	animalType = "Oviparous";
}

string Oviparous::GetType()
{
	return animalType;
}

//This allows a forced assignment for filereaders and an assignmnet with prompt for users
void Oviparous::SetNumberOfEggs(int eggs)
{
	if (eggs < 0) {
		NumberOfEggs = handlingObj.GetUserInteger("How many eggs does animal have? " , 1000, 0);
	}
	else {
		NumberOfEggs = eggs;
	}

}

//This is two default getters classes, one for eggs and the other for nursing
int Oviparous::GetNumberOfEggs()
{
	return NumberOfEggs;
}

int Oviparous::GetNursing()
{
	return nursing;
}
