# CS-210_SNHU
This repository is for my CS-210 class focusing on C++


As you can see by the general layout of this program the program uses multiple classes as a basis for a txt file database.

In this project the Animal Abstract class is the base class from which all other animals are built

The Oviparuas and Mammal classes are derived classes from animal that add type specific abstraction while
adding default values based off their type.

Finally, there are 6 child classes, three for each type that are subtypes, they are children to the derived classes
and therefore inherit from both their direct parents and the base class animal allowing for each individual animal to have different traits as needed.

The input handling class is used to handle user input for the needs of all the other classes and can be taken for use in other
projects. 

TheZoo.cpp contains the main body of the program allowing for adding removing, saving and loading the animal database and
maintains format to ensure continued use will not degreade data recovery over time.
