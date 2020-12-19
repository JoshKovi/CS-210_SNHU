/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This Is the Crocodile class like all other SubType classes it is extremely basic
*/
#include "../Header Files/Crocodile.h"
using namespace std;

//This class contains two constructors, one for calling the parent constructors, and two default functions,
//Similar to Batt class
Crocodile::Crocodile()
{
	SetSubType();
}
Crocodile::Crocodile(bool userEntry) : Oviparous(userEntry) {
	SetSubType();
}

void Crocodile::SetSubType()
{
	animalSubType = "Crocodile";
}

string Crocodile::GetSubType()
{
	return animalSubType;
}
