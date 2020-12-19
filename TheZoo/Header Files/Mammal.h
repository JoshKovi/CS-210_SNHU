/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the Mammal child/parent class, they are all roughly the same
*/


#pragma once
#include "../Header Files/Animal.h"
using namespace std;

class Mammal :
	public Animal
{
public:
	//Above is the inheritence from the animal class
	InputHandling handlingObj;


	//This is where the two constructors are declared
	Mammal(); 
	Mammal(bool userEntry);

	//This is the setter and getter for the Type variable
	void SetType();
	string GetType();

	//This is the setter and getter for the nursing variable
	void SetNursing(int nurse = -1);
	int GetNursing();

	//This is a required getter for the animal class
	int GetNumberOfEggs();

protected:

	//These are the three protected variables of the mammal class and Oviparous class
	string animalType;
	int NumberOfEggs;
	int nursing;
};

