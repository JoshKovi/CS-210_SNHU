/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Whale class, effectively the same as all other child/derived animal classes
*/
#include "../Header Files/Whale.h"

using namespace std;

Whale::Whale()
{
	SetSubType();
}
Whale::Whale(bool userEntry) : Mammal(userEntry) {
	SetSubType();
}

void Whale::SetSubType()
{
	animalSubType = "Whale";
}

string Whale::GetSubType()
{
	return animalSubType;
}
