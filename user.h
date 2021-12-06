/**
 * This is the header file containg the User class, which deals with all the UI for the program. 
 */
#include <iostream>
#include "Wav.h"
#include "Processor.h"


class User {
private:

    //0 or 1, indicates whether user wants to load a file or exit
    int menuOption;
    //filename entered by the user
	std::string inputFilename;
    //indicates the status of the program
    bool wavProcess;
    //processor option, 1, 2 or 3
    int processorChoice;
    //filename of the outputted file
    std::string outputFile;
    //file being processed
    Wav* input;

    Wav output;

public:

    /**
     * 
     * Default constructor
     * 
     */
    User();


    /**
     * 
     * getStatus() will get the status of the program for the main while loop
     * 
     */
    bool getStatus();

    /**
     *
     * initialOptions() will display the start menu to the user and take in the choice 
     * 
     */
    void printInitialOptions();


    /**
     * 
     * fileOptions() will prompt the user for a filename if chosen, check for errors opening the file, then 
     * present processor options to user.
     * If user file doesn't open, user chooses to exit, or an invalid choice is chosen, start menu reopens.
     * 
     */
    void fileOptions();
    

    /**
     * 
     * loadFile() will ask the user for a filename, and load the file
     * into memory, 
     * 
     */
    void loadFile();


    /**
     * 
     * printFileInfo() will print all the necessary file information 
     * to the console
     * 
     */
    void printFileInfo();


    int selectProcessorOption();


    std::string getOutputFilename();


    Wav process(int process);
};
