/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is a header for one of the children, they are all roughly the same
*/


#pragma once
#include "Mammal.h"
using namespace std;
class Bat :
	public Mammal
{
	//Above is how the class inherits from mammal which in trun inherits from animal
public:

	//Two constructors one setter and one getter are declared here
	Bat();
	Bat(bool userEntry);
	void SetSubType();
	string GetSubType();

private:
	//this is the private variable SubType that only the child classes can access and modify
	//Ass it directly pertains to them
	string animalSubType;

};

