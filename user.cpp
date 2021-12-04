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
        std::cout << "*******************************" << std::endl;

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
				//display file metadata somewhere

                std::cout<<"*******************************"<<std::endl;
                std::cout<<"Processor Menu"<<std::endl;
                std::cout<<"1. Normalization"<<std::endl;
				std::cout<<"2. Echo"<<std::endl;
                std::cout<<"3. Gain adjustment"<<std::endl;
                std::cout<<"*******************************"<<std::endl;

                std::cin >> processorChoice;
                if(processorChoice != 0)
                {
                    std::cout<<"Output Filename?"<<std::endl;
                    std::cin >> outputFile;
                    //run processor
                    //save file
                    initialOptions();
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
				break;
		}

	}
   

