#include <iostream>
#include <memory>
#include "Wav.h"
#include "Processor.h"


//char array *argv is a commandline argument
// TODO: make file runnable with argv
/**
 * 
 * OUTLINE: main() should:
 * 		take file as input
 * 		load file and the data
 * 		ask user for effects / options corresponding to effects
 * 		process successfully
 * 		return output in (new?) file
 * 
 */
int main(int argc, char *argv[]) {

	int choice;
	std::string filename;
	std::string newFname;


	bool wavProcess = true;
	while (wavProcess != false) { // lmao
		
		
		// TODO: maybe make this initial print/case sections their own functions
		std::cout << "*******************************" << std::endl;
		std::cout << " 1 - Load File" << std::endl;
		std::cout << " 2 - Quit." << std::endl;
		std::cout << " Enter your choice and press return: ";

		std::cin >> choice;

		Wav *wav = new Wav();


		switch (choice)
		{
			case 1:
				std::cout << "Enter Filename:";
				std::cin >> filename;

				filename = "yes-8-bit-mono.wav";
				newFname = "newFile.wav"; //TEMP

				std::cout << "Loading file.." << std::endl;
				try {
					// TODO: add flow of effects processing

					wav = new Wav(filename, newFname);
					
					wav->printBuffer();

					
					
				}
				catch(const std::exception ex){
					std::cout << "An exception occurred on opening the file:" << ex.what() << std::endl;
				}
				
				
				wavProcess = false;
				break;
	
			case 2:
				std::cout << "Exiting..." << std::endl;
				wavProcess = false;
				break;
	
			default:
				std::cout << "Not a Valid Choice." << std::endl;
				std::cout << "Choose again." << std::endl;
				std::cin >> choice;
				break;
		}

	}
	return 0;
} 
