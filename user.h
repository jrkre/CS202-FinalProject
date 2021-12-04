/**
 * This is the header file containg the User class, which deals with all the UI for the program. 
 */
#include <iostream>


class User {
private:
    int choice;
	std::string filename;
	std::string newFname;
    bool wavProcess = true;
    int processorChoice;
    std::string outputFile;

public:

/**
 * Default constructor
 */
User();

/**
 * initialOptions() will display the start menu to the user and take in the choice 
 */
void initialOptions();

/**
 * fileOptions() will prompt the user for a filename if chosen, check for errors opening the file, then 
 * present processor options to user.
 * If user file doesn't open, user chooses to exit, or an invalid choice is chosen, start menu reopens.
 */
void fileOptions();


};