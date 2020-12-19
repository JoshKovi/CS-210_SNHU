/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This Is the bat animal cpp class with constructors, and with a setter and getter for SubType
*/
#include "../Header Files/Bat.h"

using namespace std;

//This is the default constructor, as a Bat is always a Bat it is extremely basic. Calling a default setter
Bat::Bat()
{
	SetSubType();
}
//This is a custom constructor that allows me to call parent class constructors with the bool discussed in Animal.cpp
//For the purposes of bat this is exactly the same as calling the default constructor
Bat::Bat(bool userEntry): Mammal(userEntry)
{
	SetSubType();
}

//This is a default setter that only sets Bat animals to the bat subtype
void Bat::SetSubType()
{
	animalSubType = "Bat";
}

//This is a default Getter class for SubType
string Bat::GetSubType()
{
	return animalSubType;
}
