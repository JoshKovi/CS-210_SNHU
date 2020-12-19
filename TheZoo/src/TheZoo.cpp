/*
Name: Joshua Kovacevich
Course: CS-210
Project: Project Three: The Zoo Animals
Date 20201213

Description: This is the Zoo cpp class and it contains the main function and the majority of the code for the entire project
*/

//These are the standard required dependencies including the JNI
#include <iostream>
#include <jni.h>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>


//These are the user made headerfiles that handle the majority of the individual assignment of variables, InputHandling was
//The easiest way to reproduce code the entire project could use for ease and consistency
#include "../Header Files/InputHandling.h"

#include "../Header Files/Animal.h"
#include "../Header Files/Mammal.h"
#include "../Header Files/Oviparous.h"
#include "../Header Files/Bat.h"
#include "../Header Files/Crocodile.h"
#include "../Header Files/Goose.h"
#include "../Header Files/Pelican.h"
#include "../Header Files/SeaLion.h"
#include "../Header Files/Whale.h"

using namespace std;

//This is the only needed identifer out of the order of the class
void DisplayData(vector<Animal*>);


//This is the JNI code that has not been touched!
void GenerateData()               //DO NOT TOUCH CODE IN THIS METHOD
{

	JavaVM *jvm;                      // Pointer to the JVM (Java Virtual Machine)
	JNIEnv *env;                      // Pointer to native interface
															 //================== prepare loading of Java VM ============================
	JavaVMInitArgs vm_args;                        // Initialization arguments
	JavaVMOption* options = new JavaVMOption[1];   // JVM invocation options
	options[0].optionString = (char*) "-Djava.class.path=";   // where to find java .class
	vm_args.version = JNI_VERSION_1_6;             // minimum Java version
	vm_args.nOptions = 1;                          // number of options
	vm_args.options = options;
	vm_args.ignoreUnrecognized = false;     // invalid options make the JVM init fail
																		 //=============== load and initialize Java VM and JNI interface =============
	jint rc = JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);  // YES !!
	delete options;    // we then no longer need the initialisation options.
	if (rc != JNI_OK) {
		// TO DO: error processing...
		cin.get();
		exit(EXIT_FAILURE);
	}
	//=============== Display JVM version =======================================
	cout << "JVM load succeeded: Version ";
	jint ver = env->GetVersion();
	cout << ((ver >> 16) & 0x0f) << "." << (ver & 0x0f) << endl;

	jclass cls2 = env->FindClass("ZooFileWriter");  // try to find the class
	if (cls2 == nullptr) {
		cerr << "ERROR: class not found !";
	}
	else {                                  // if class found, continue
		cout << "Class MyTest found" << endl;
		jmethodID mid = env->GetStaticMethodID(cls2, "createZooFile", "()V");  // find method
		if (mid == nullptr)
			cerr << "ERROR: method void createZooFile() not found !" << endl;
		else {
			env->CallStaticVoidMethod(cls2, mid);                      // call method
			cout << endl;
		}
	}


	jvm->DestroyJavaVM();
	cin.get();
}
//End Scary JNI code



void AddAnimal(vector<Animal*> &vectorAnimal, InputHandling &inputHandler)
{
	//This is the function for adding animals to the working memory, it requires two parameters, An animal point vector and an inputhandler

	//Here a prompt string is assigned (its reused several times) and the userInput char is initiated
	char userInput;
	string promptString = "What Type of animal would you like to add, (M) Mammal or (O) Oviparious: ";

	//This is a friendly not to all users they can quit or restart the menu whenever they choose
	cout << "At any time press 'q' to exit or 'r' to restart. Shortcuts are also enabled if you are familar with the menu." << endl;


	//This was a nicely crafted switch statement, but C++ didn't like that due to cases skipping over initialization(kinda the point)
	//This do while loop allows me to limit the nested if/else loops and allows users to shortcut as most people who would use this program
	//Would probably not like to be forced through every prompt when they are already familiar with the menus

	do {
		//This uses the inputHandler for menu slections with a char
		userInput = inputHandler.GetFirstChar(promptString);


		//tolower was the most efficient way of coding these if/else statements in comparison to || statements in each
		//Fall through switch cases would be prefered but C++ didn't like it.
		if (tolower(userInput) == 'r') {
			//R simply recalls the function from scratch
			AddAnimal(vectorAnimal, inputHandler);
		}
		else if (tolower(userInput) == 'q') {
			//Q quits the while loop
			continue;
		}
		else if (tolower(userInput) == 'm') {
			//M allows the user to see mammal options
			promptString = "What type of Mammal would you like to add, the options are (B) for Bats, (W) for Whale, or (S) Sealion: \n";
		}
		else if (tolower(userInput) == 'o') {
			//O allows the user to see Oviparious options
			promptString = "What type of Oviparious would you like to add, the options are (C) for Crocodile, (P) for Pelican, or (G) Goose: \n";
		}
		else if (tolower(userInput) == 'b') {
			//B Directly creates a new Bat object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			Bat* newBat = new Bat(true);
			cout << "Bat was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newBat);
			cout << "Press q to return to main menu." << endl;
		}
		else if (tolower(userInput) == 'w') {
			//W Directly creates a new Whale object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			Whale* newWhale = new Whale(true);
			cout << "Whale was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newWhale);
			cout << "Press q to return to main menu." << endl;
		}
		else if (tolower(userInput) == 's') {
			//S Directly creates a new SeaLion object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			SeaLion* newSeaLion = new SeaLion(true);
			cout << "SeaLion was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newSeaLion);
			cout << "Press q to return to main menu." << endl;
		}
		else if (tolower(userInput) == 'c') {
			//C Directly creates a new Crocodile object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			Crocodile* newCrocodile = new Crocodile(true);
			cout << "Crocodile was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newCrocodile);
			cout << "Press q to return to main menu." << endl;
		}
		else if (tolower(userInput) == 'p') {
			//P Directly creates a new Pelican object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			Pelican* newPelican = new Pelican(true);
			cout << "Pelican was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newPelican);
			cout << "Press q to return to main menu." << endl;
		}
		else if (tolower(userInput) == 'g') {
			//g Directly creates a new Goose object and pointer,
			//this creation will prompt the user through all necessary fields then will inform the user
			//when creation is completed The objects point is then added to the vectorAnimal vector
			Goose* newGoose = new Goose(true);
			cout << "Goose was created! (Don't forget to save)" << endl;
			vectorAnimal.push_back(newGoose);
			cout << "Press q to return to main menu." << endl;
		}
		else {
			//This handles most invalid input
			promptString = " Incorrect or invalid input, please follow the prompts";
		}
	} while (tolower(userInput) !=  'q');

	return;
}


void RemoveAnimal(vector<Animal*> &vectorAnimal, InputHandling &inputHandler)
{
	//This function allows a user to remove a animal from memory (and delete them) based of a tracking number and/or name

	//Here are the required input variables for the function
	char userInput;
	string userString;

	//This clearly displays all options for user to clearly see which animal they would like to remove.
	DisplayData(vectorAnimal);

	//This informs user they can quite at any time and then uses InputHander's GetFirstChar function to
	//select an option
	cout << "Press 'q' to quit at any time. " << endl;
	userInput = inputHandler.GetFirstChar(" Would you like to delete by (N) Name or (T) Tracking Number? ");
	//Q lets a user leave menu, and then to main menu
	if (tolower(userInput) == 'q') {
		return;
	}
	else if (tolower(userInput) == 'n') {
		//This selection is for name, here the user is prompted for enough characters to match the name or similar names
		userString = inputHandler.GetUserString("Please enter a full or partial name: ");
		for (unsigned int i = 0; i < vectorAnimal.size(); i++) {
			//This for loop cycles through the vector of animal objects and compares thei AnimalNa,e variable to the searched for name
			if (vectorAnimal.at(i)->GetAnimalName().find(userString) <= vectorAnimal.at(i)->GetAnimalName().size()) {
				//This if statement determine that a near match is in this object and prompts user for verifications
				cout << "Are you sure you would like to delete " << vectorAnimal.at(i)->GetAnimalName() << " (Y/N): " << endl;
				userInput = inputHandler.GetFirstChar("");

				//This deletes the user selected object and as it is deleted the animal destructor finishes the job
				if (tolower(userInput) == 'y') {
					cout << "Animal Has been deleted." << endl;
					//This is used to remove its pointer from this vector
					vectorAnimal.erase(vectorAnimal.begin() + i);

				}
				else {
					//action was defered menu restarts
					cout << "No deletion action taken. " << endl;
				}
			}
		}
		//This Is a recursion call of removeAnimal
		RemoveAnimal(vectorAnimal, inputHandler);
	}

	else if (tolower(userInput) == 't') {
		//This is for a user who has selected trackingNuimber as the selection source, here the user is allowed any number between 0 and 1M
		// As this is the range that tracking IDs can fall in
		userString = to_string(inputHandler.GetUserInteger("Please enter a full or partial number (3 or more numbers): ", 1000000 , 0));
		for (unsigned int i = 0; i < vectorAnimal.size(); i++) {
			//Excatly the same was as the above function searches, prompts and deletes animals in the name for loop,
			//this for loop does the same but calling the GetTrackingNumber function
			if (to_string(vectorAnimal.at(i)->GetTrackingNumber()).find(userString) <= to_string(vectorAnimal.at(i)->GetTrackingNumber()).size()) {
				//IF the user accepts the prompt and selects y the animal object will be deleted the same as it is done above.
				cout << "Are you sure you would like to delete " << vectorAnimal.at(i)->GetTrackingNumber() << " (Y/N): " << endl;
				userInput = inputHandler.GetFirstChar("");
				if (tolower(userInput) == 'y') {
					cout << "Animal Has been deleted." << endl;
					vectorAnimal.erase(vectorAnimal.begin() + i);

				}
				else {
					//Deletion is defered
					cout << "No deletion action taken. " << endl;
				}
			}
		}
		//Recursion call is made
		RemoveAnimal(vectorAnimal, inputHandler);
	}
}

void LoadDataFromFile(vector<Animal*> &animalVector)
{
	//This function loads the data from the file (created by the JNI) and then stores that information retireved
	//in instances of class objects that have their pointers added to a vector for easy keeping track

	//fstream is for filestream, zoodata is the reader object and the .txt file, string currentFileLine
	//is used to effectively manage data assignment
	fstream zoodata;
	zoodata.open("zoodata.txt", ios::in);
	string currentFileLine;


	//Ensures file is open before attempting to loop through and read it
	if (zoodata.is_open()) {

		//This while loop will continue to execute until the file is empty
		while (getline(zoodata, currentFileLine)) {


			//This if else tree is bulking and ugly but I could not find an effective non comprimising way to handle the assignment of
			//data to individualized and uninitialized classes. All And all I spent at least 10 hours in this function of the the project and
			//While I learned alot I would have prefered to handle this in another language, in javascript or python this task could be
			//handled and completed without any complications in a handful of lines of code. For the purposes of the course I will only explain one of the if branches
			if (currentFileLine.find("Bat") <= currentFileLine.size()) {
				//This if branch creates a derived class of animal with a pointer, then assigns all required fields using the
				//previously discussed default constructors of the animals and derived classes, finally the objects pointer is added to the vector
				Bat* newAnimal = new Bat();
				newAnimal->SetNursing(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else if (currentFileLine.find("Crocodile") <= currentFileLine.size()) {
				Crocodile* newAnimal = new Crocodile();
				newAnimal->SetNumberOfEggs(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else if (currentFileLine.find("Goose") <= currentFileLine.size()) {
				Goose* newAnimal = new Goose();
				newAnimal->SetNumberOfEggs(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else if (currentFileLine.find("Pelican") <= currentFileLine.size()) {
				Pelican* newAnimal = new Pelican();
				newAnimal->SetNumberOfEggs(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else if (currentFileLine.find("Whale") <= currentFileLine.size()) {
				Whale* newAnimal = new Whale();
				newAnimal->SetNursing(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else if (currentFileLine.find("SeaLion") <= currentFileLine.size()) {
				SeaLion* newAnimal = new SeaLion();
				newAnimal->SetNursing(stoi(currentFileLine.substr(currentFileLine.rfind(" ") + 1, currentFileLine.size() - 1)));
				newAnimal->SetTrackingNumber(stoi(currentFileLine.substr(0, 5)));
				newAnimal->SetAnimalName(currentFileLine.substr(7, 15));
				animalVector.push_back(newAnimal);
			}
			else {
				continue;
			}

		}
		//Here the zoodata fstream reader is closed
		zoodata.close();
	}

}

void SaveDataToFile(vector<Animal*> &animalVector)
{
	//This section uses the fstream zoodata to save text in a formated way into the .txt file
	//The majority of this code is extremely simple but is required to get the text just write in the
	//output file
	fstream zoodata;
	zoodata.open("zoodata.txt", ios::out);
	//GenerateData(); FIXME: Works in eclipse, not in VS
	if (zoodata.is_open()) {
		for (unsigned int i = 0; i < animalVector.size(); i++) {
			zoodata << setw(6) << setfill('0') << animalVector.at(i)->GetTrackingNumber() << " ";
			zoodata << setw(15) << left << setfill(' ') << animalVector.at(i)->GetAnimalName() << " ";
			zoodata << setw(15) << setfill(' ') << animalVector.at(i)->GetType() << " ";
			zoodata << setw(15) << setfill(' ') << animalVector.at(i)->GetSubType() << " ";
			zoodata << setfill(' ') << animalVector.at(i)->GetNumberOfEggs() << " ";
			zoodata << setfill(' ') << animalVector.at(i)->GetNursing() << endl;

		}
		zoodata.close();
	}
	//Here I erase the entire vector to limit redundent entries if a user reloads from the saved file immediately following
	animalVector.erase(animalVector.begin(),  animalVector.end());
}


string StringFormat(string inputString, size_t charCount, bool centered = false) {

	//This is a simply string formatter only used by the display menu to ensure proper and
	//astetically accepticable output to the console. Effectively it spaces text and draws the left and right borders
	if (centered) {
		string placeholder = "";
		for (unsigned int i = 0; i < charCount; i++) {
			placeholder += " ";
		}
		inputString = "|" + placeholder + inputString + placeholder + "|";
	}
	else {
		inputString.resize(charCount, ' ');
		inputString = "|" + inputString + "|";
	}
	return inputString;
}

void DisplayMenu()
{
	/*
					INTENDED USER DISPLAY APPEARANCE:
				 =======================================
				|               Main Menu               |
				 =======================================
				|(1) Load Animal Data                   |
				|(2) Generate Data                      |
				|(3) Display Animal Data                |
				|(4) Add Record                         |
				|(5) Delete Record                      |
				|(6) Save Animal Data                   |
				|(7) Exit                               |
				 =======================================

		 */

		 //This vector is made to make the print loop easier to write, understand, and modify
	vector<string> options = { "Main Menu", "(1) Load Animal Data", "(2) Generate Data", "(3) Display Animal Data",
			"(4) Add Record", "(5) Delete Record", "(6) Save Animal Data", "(7) Exit" };
	//This divider string will be used 3 times and will have its length used for ease of formatting,
	//changing this string will directly change the width of the menu
	string divider = "=======================================";

	for (unsigned int i = 0; i < options.size(); i++) {
		//This for loop is for easier output and easier changes to that output
		if (i == 0) {
			cout << endl << " " << divider << " " << endl;
			cout << StringFormat(options.at(i), (divider.size() - 9) / 2, true) << endl;
			cout << " " << divider << " " << endl;
		}
		else if (i + 1 == options.size()) {
			cout << StringFormat(options.at(i), divider.size()) << endl;
			cout << " " << divider << " " << endl;
			cout << "Please enter a selection: ";
		}
		else {
			cout << StringFormat(options.at(i), divider.size()) << endl;
		}
	}
}


void DisplayData(vector<Animal*> animalVector) {



	//This was another difficult part for me, not the display which is relatively simply, but accessing the data was actually very
	//hard for me, then I realized I wasted several hours because of a syntax mistake when populting the vector and everything suddenly got better

	cout << " ===============================================================================" << endl;
	cout << "|Tracking #    | Name          | Type          | Sub Type      | Eggs | Nursing |" << endl;
	cout << " ===============================================================================" << endl;


	//cout << animalVector.at(0)->GetAnimalName() << endl;
	int formHelper = 0;

	for (unsigned int i = 0; i < animalVector.size(); i++) {
		//This for loop iterates one time per lin and this code allows all the text to go eactly where it needs to with widths, filling and alignment changes
		cout << "|" << i + 1 << ".  " << setw(6) << setfill('0') << animalVector.at(i)->GetTrackingNumber()<< " ";
		cout << setfill(' ') << setw(3-formHelper) <<  "| " << setw(10) << left << animalVector.at(i)->GetAnimalName();
		cout << "| " << setw(14) << left << animalVector.at(i)->GetType();
		cout << "| " << setw(13) << left << animalVector.at(i)->GetSubType();
		cout << "| " << setw(6) << internal << animalVector.at(i)->GetNumberOfEggs();
		cout << "| " << setw(7) << internal << animalVector.at(i)->GetNursing() << "|" << endl;

		//This is to mitigate shifts in the table formating.
		if (i + 1 == 9) {
			formHelper++;
		}
		else if (i + 1 == 99) {
			formHelper++;
		}
		else if (i + 1 == 999) {
			formHelper++;
		}
	}
	cout << " ===============================================================================" << endl;


}


int main()
{

	//Finally after nearly 500 lines of code we come to the main function where the primary loop and main menu are utilized

	//The userSelection variable is for userChar input, the vector of animal pointers allows easy management
	//Without a linked list, (I try and struggled, overcomplicated the code and eventually needed to scrap the idea to meet the deadline I am pushing now
	//The inputhandler was discussed elsewhere, here is where it is instantiated and passed from.
	char userSelection;
	vector<Animal*> animalVector;
	InputHandling inputHandler;


	//This is the main loop that surrounds a switch statement. The main loop is just 7 selections that call the appropriate functions
	//Pass the appropriate parameter and display the menu options and some small text prompts.
	do {
		DisplayMenu();
		userSelection = inputHandler.GetFirstChar("");

		switch (userSelection) {
		case '1':
			//This loads data from file
			cout << "Loading Animal Data" << endl;
			cout << "Press any Button to continue." << endl;
			LoadDataFromFile(animalVector);
			break;
		case '2':
			//This generates a file with JNI function, can delete already present files occassionally
			cout << "Generate Data will delete all data currently saved and" << endl;
			cout << "generate a new empty file, would you like to continue? (Y/N): " << endl;
			userSelection = inputHandler.GetFirstChar("");
			if (userSelection == 'y' || userSelection == 'Y') {
				GenerateData();
				cout << "New file has been generated." << endl;
			}
			else {
				cout << "File was not generated." << endl;
			}
			break;
		case '3':
			//This displays the current memory of animals
			//After it is loaded by option 1
			cout << "Display Animal Data" << endl;
			DisplayData(animalVector);
			break;
		case '4':
			//This adds an animal(s)
			cout << "Add Record" << endl;
			AddAnimal(animalVector, inputHandler);
			break;
		case '5':
			//This deletes an animal
			cout << "Delete Record" << endl;
			RemoveAnimal(animalVector, inputHandler);
			break;
		case '6':
			//This saves temporary memory to the file for permenant storage
			cout << "Save Animal Data" << endl;
			SaveDataToFile(animalVector);
			break;
		case '7':
			//This exits the programs and main loop
			cout << "Goodbye..." << endl;
			continue;
			break;
		default:
			//This is default and its effectively a placeholder.
			cout << "Generate Data" << endl;
			break;
		}

		//This puts line spaces between each iteration
		for (int i = 0; i < 10; i++) {
			cout <<  endl;
		}
	} while (userSelection != '7');

	return 1;
}
