/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Goose Class, similar to all other animal child classes with a setter, getter and two constructors
//See bat for more info
*/
#include "../Header Files/Goose.h"

using namespace std;

Goose::Goose()
{
	SetSubType();
}
Goose::Goose(bool userEntry) : Oviparous(userEntry) {
	SetSubType();
}

void Goose::SetSubType()
{
	animalSubType = "Goose";
}

string Goose::GetSubType()
{
	return animalSubType;
}
