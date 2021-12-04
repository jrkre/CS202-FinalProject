#include <iostream>
#include "user.h"
#include "Wav.h"
#include "Processor.h"



    
	void User::initialOptions()
    {	
        
	    while (wavProcess != false) {
		std::cout << "*******************************" << std::endl;
		std::cout << " 1 - Load File" << std::endl;
		std::cout << " 2 - Quit." << std::endl;
		std::cout << " Enter your choice and press return: ";

		std::cin >> choice;
		

		Wav *wav = new Wav();
        }
    }

    void User::fileOptions()
    {
		switch (choice)
		{
			case 1:
				std::cout << "Enter Filename:";
				std::cin >> filename;

				filename = "yes-8-bit-mono.wav";
				newFname = "newFile.wav"; //TEMP

				std::cout << "Loading file..." << std::endl;
				try 
                {
					// TODO: add flow of effects processing

					Wav *wav = new Wav(filename, newFname);
					
					wav->printBuffer();

					
					
				}
				catch(const std::exception ex)
                {
					std::cout << "An exception occurred on opening the file:" << ex.what() << std::endl;
                    
				}
				
				
				wavProcess = false;
                initialOptions();
				break;
	
			case 2:
				std::cout << "Exiting..." << std::endl;
				wavProcess = false;
                initialOptions();
				break;
	
			default:
				std::cout << "Not a Valid Choice." << std::endl;
				std::cout << "Choose again." << std::endl;
				std::cin >> choice;
                initialOptions();
				break;
		}

	}
   

