/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the header file for the abstract Animal Class
*/


#pragma once

#include <string>
#include "../Header Files/InputHandling.h"

using namespace std;


class Animal
{
	//These are the publically accessable items from the animal class the UML wasn't very clear
	//And contradictory UMLs in the same document for the setup of this project so it may not be ideal
	public:
		//This allows all the use of the input handling class for ease
		InputHandling handlingObj;

		//Default constructor, overloaded constructor and destructor (destructor ended up being unnecessary for end product)
		Animal();
		Animal(bool userEntry);
		~Animal();

		//Here are the setters two of which are defined in the .cpp two are inline
		//empty classes and two are virtual to be handled by the child classes
		void SetAnimalName(string name);
		void SetTrackingNumber(int trackingNum);
		virtual void SetType() = 0;
		virtual void SetSubType() = 0;
		void SetNursing(int nursing = 0) {
			
		}
		void SetNumberOfEggs(int eggs = 0) {

		}

		//All classes require access to these variables so the getters are all public
		//4 are virtual for the derived classes and two are handled by this parent class
		string GetAnimalName();
		int GetTrackingNumber()const;
		
		virtual string GetType() = 0;
		virtual string GetSubType() = 0;
		virtual int GetNumberOfEggs() = 0;
		virtual int GetNursing() = 0;

		
		

	protected:
		//These are the protected variables name and trackNumber
		string animalName;
		int trackNumber;

};

