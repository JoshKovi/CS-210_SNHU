/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the SeaLion child class, they are all roughly the same
*/


#pragma once
#include "../Header Files/Mammal.h"

using namespace std;

class SeaLion :
	public Mammal
{
public:

	//Two constructors, a setter and getter with a private subtype variables
	SeaLion();
	SeaLion(bool userEntry);
	void SetSubType();
	string GetSubType();

private:
	string animalSubType;

};

