/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the SeaLion class, effectively the same as all other child/derived animal classes
see bat for more info
*/

#include "../Header Files/SeaLion.h"

using namespace std;

SeaLion::SeaLion()
{
	SetSubType();
}
SeaLion::SeaLion(bool userEntry) : Mammal(userEntry) {
	SetSubType();
}

void SeaLion::SetSubType()
{
	animalSubType = "SeaLion";
}

string SeaLion::GetSubType()
{
	return animalSubType;
}
