/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Mammal parent class, technically is abstract, but could easily be modified outside current interface/intermediary role
//This is the parent to the whale the SeaLion and the Bat
*/
#include "../Header Files/Mammal.h"
using namespace std;


//This is the default constructor and is used to avoid prompting users when reading from a file
Mammal::Mammal() {
	SetType();
	NumberOfEggs = 0;
}

//This constructor calls the parent constructor of animal and assigns/calls a prompt to set Nursing variable
Mammal::Mammal(bool userEntry): Animal(userEntry) {
	//Sets type to mammal by default, Eggs to 0 as mammals dont have eggs(but for reusable code they need the variable
	//Then Calls SetNursing which prompts user for response
	SetType();
	NumberOfEggs = 0;
	SetNursing();
}

//Basic defualt type setting
void Mammal::SetType() {
	animalType = "Mammal";
}

void Mammal::SetNursing(int nurse)
{
	The parameter nurse allow file readers to use the same function and indirectly assign nursing variable
	if (nurse < 0) {
		//If default (-1) value is sent to Set Nursing user is prompted if animal is nursing
		nursing = handlingObj.GetUserInteger("Is animal nursing? Enter 0 if no, 1 is yes", 2);
	}
	else {
		nursing = nurse;
	}
}


//These are three default getters
string Mammal::GetType() {
	return animalType;
}

int Mammal::GetNursing()
{
	return nursing;
}

int Mammal::GetNumberOfEggs() {
	return NumberOfEggs;
}

