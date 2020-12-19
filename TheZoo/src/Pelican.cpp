/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Pelican class, effectively the same as all other child/derived animal classes
//See bat for more info
*/
#include "../Header Files/Pelican.h"

using namespace std;

Pelican::Pelican()
{
	SetSubType();
}
Pelican::Pelican(bool userEntry) : Oviparous(userEntry) {
	SetSubType();
}

void Pelican::SetSubType()
{
	animalSubType = "Pelican";
}

string Pelican::GetSubType()
{
	return animalSubType;
}
