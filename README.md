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



Summary:
This project is a prototype of a repository for zoo animals, this project could be fully developed to contain an entire zoos
animal searchable by tracking number and name with all pertinent information. This reduces the amount of manual input that 
something like an excel spreadsheet would require.

What I did well:
I personally believe I did an adequate job of handling inheritenance and all basic required functions. In particular,
I think my handling of user input was critical in the success of this program and I will likely maintain and build on the
InputHandling file I use here in future projects.

Where I could improve:
I think I could make improvements to my output and data pulling to a file. Given some modifications I believe I could make the code
required to output and input the data significantly easier to read and follow without comments. This could potentially remove several dozen
lines of code from the project and would drastially improve on the efficiency of the code. I also think I could use a function to inject titles
into the txt file database on generation of the file with the JNI which would eliminate a failure point for of the program.

Did I find writing this code challenging:
Yes, initially I had went through a completely different way of handling animal objects and after a significant amount of time decided I did not have the technical knowledge
to fully realize the end goals of that approach. I had to scrap nearly the entireity of the first version of this project and restart from effectively zero. 
Due to this project I actually bought the book "Programming Principles and Practice Using C++" by Bjarne Stroustrup to enhance my skills and reference material.
I figured that if anybody can take my skills in C++ to the next level, the creator of the language would stand the best chance outside of myself.

What Skills from this project will be transferable:
I think what I learned about pointers and inheritance, and my input handling processes will be particularly transferable to other projects and course work.
I also got a lot of experience with the reference library/documentation of C++ that will help me long past my completion of this degree program.

How did I make this program maintainable, readable and adaptable:
I used inheritance to best enable additional classes and animals being added in to make this program adaptable. I commented the code pretty excessively
to ensure that almost anyone would be able to read and understand what each block of code is doing and why. Finally, I used object oriented programming
with the use of classes and independent variables and functions to make this code maintainable so that if a new programmer breaks one piece of the program
when trying to change the functionality the entire program does not break. 
