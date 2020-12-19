/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the Pelican child class, they are all roughly the same
*/


#pragma once
#include "../Header Files/Oviparous.h"

using namespace std;

class Pelican :
	public Oviparous
{
public:

	//Two constructors, a setter and getter with a private subtype variables
	Pelican();
	Pelican(bool userEntry);
	void SetSubType();
	string GetSubType();

private:
	string animalSubType;

};

