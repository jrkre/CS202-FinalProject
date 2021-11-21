#include <iostream>

int main() {
	
	int choice;
	bool wavProcess = true;
	while (wavProcess != false) {
		std::cout << "*******************************" << std::endl;
		std::cout << " 1 - Load File" << std::endl;
		std::cout << " 2 - Quit." << std::endl;
		std::cout << " Enter your choice and press return: ";

		std::cin >> choice;
`
		switch (choice)
		{
			case 1:
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
