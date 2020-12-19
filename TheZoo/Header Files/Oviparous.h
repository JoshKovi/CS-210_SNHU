/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header for the Oviparous child/parent class, they are all roughly the same
*/


#pragma once
#include "../Header Files/Animal.h"


using namespace std;
class Oviparous :
	public Animal
{
public:
	//Above is the inheritence from the animal class

	//This is the InputHandling Object
	InputHandling handlingObj;

	//Two constructors
	Oviparous();
	Oviparous(bool userEntry);

	//Setter and getter for type
	void SetType();
	string GetType();

	//Setters and getters fro Number of eggs
	void SetNumberOfEggs(int eggs = -1);
	int GetNumberOfEggs();

	//This is the required get nursing function from the parent class
	int GetNursing();


protected:
	//These are three protected variables both the child/parent classes utilize
	string animalType;
	int NumberOfEggs;
	int nursing;
};

