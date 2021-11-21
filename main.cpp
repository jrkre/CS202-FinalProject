#include <iostream>
#include "Wav.h"


int main() {

	int choice;
	std::string filename;
	

	bool wavProcess = true;
	while (wavProcess != false) { // lmao
		std::cout << "*******************************" << std::endl;
		std::cout << " 1 - Load File" << std::endl;
		std::cout << " 2 - Quit." << std::endl;
		std::cout << " Enter your choice and press return: ";

		std::cin >> choice;
		Wav wav = Wav();
		switch (choice)
		{
			case 1:
				std::cout << "Enter Filename:";
				std::cin >> filename;

				wav.readFile(filename);

				std::cout << "Loading file.." << std::endl;
				// rest of code here
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
