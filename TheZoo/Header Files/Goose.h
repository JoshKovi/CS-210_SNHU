/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header the Goose child class, they are all roughly the same
*/

#pragma once
#include "Oviparous.h"

using namespace std;

class Goose :
	public Oviparous
{
public:

	//Two constructors, a setter and getter with a private subtype variables
	Goose();
	Goose(bool userEntry);
	void SetSubType();
	string GetSubType();

private:
	string animalSubType;

};

