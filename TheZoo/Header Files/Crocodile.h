/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the crocodile child class, they are all roughly the same
*/


#pragma once
#include "../Header Files/Oviparous.h"

using namespace std;

class Crocodile :
	public Oviparous
{
	//Inheritenance above
public:

	//Two constructors, a setter and getter with a private subtype variables
	Crocodile();
	Crocodile(bool userEntry);
	void SetSubType();
	string GetSubType();

private:
	string animalSubType;

};

