#include "user.h"


User::User(){ wavProcess = true; }

bool User::getStatus()
{
	return wavProcess;
}

void User::printInitialOptions()
{	
    
	std::cout << "*******************************" << std::endl;
	std::cout << " 0 - Exit" << std::endl;
	std::cout << " 1 - Load File" << std::endl;
	std::cout << "Enter your choice and press return: ";
	std::cin >> menuOption;
}
    
void User::fileOptions()
{
	printInitialOptions();
	switch (menuOption)
	{
		case 1:
			loadFile();
			
			printFileInfo();
            
			if (!wavProcess)
			{
				fileOptions();
			}


			*output = process(selectProcessorOption());
			outputFile = getOutputFilename();
			output->saveFile();

			
			break;

		case 0:
			std::cout << "Exiting..." << std::endl;
			wavProcess = false;
			break;

		default:
			std::cout << "Not a Valid Choice." << std::endl;
			std::cout << "Choose again." << std::endl;
			fileOptions();
			break;
	}
}


void User::loadFile() 
{
	std::cout << "Enter Filename:";
	std::cin >> inputFilename;

				
	outputFile = "newFile.wav"; //TEMP

	std::cout << "Loading file..." << std::endl;


	try 
    {
		// TODO: add flow of effects processing
		input = new Wav(inputFilename);
		
		
	}
	catch(const std::exception ex)
    {
		std::cout << "There was an error opening the file: " << ex.what() << std::endl;
	}
}



/**
 * 

    filename

    sample rate

    bits per sample

    stereo or mono

 * 
 */
void User::printFileInfo()
{

	std::cout << "\n*****************************************" << std::endl;
	std::cout << "File information: " << std::endl;
	//filename
	std::cout << "  Filename:        " << inputFilename << std::endl;
	//sample rate
	std::cout << "  Sample Rate:     " << input->getHeader().sample_rate << std::endl;
	//bits per sample
	std::cout << "  Bits per Sample: " << input->getHeader().byte_rate << std::endl; //idk if this is right

	//print stereo or mono
	std::cout << "  Channels:        ";
	if (input->getHeader().num_channels == 1)
	{
		std::cout << "mono" << std::endl;
	}
	else 
	{
		std::cout << "stereo" << std::endl;
	}
	std::string option = "";

	std::cout << "Is this correct? (y/n)";
	std::cin >> option;
	if (option == "n")
	{
		wavProcess = false;

	}
	else if (option == "y")
	{
		std::cout << "Entering Processing...\n" << std::endl;
		
	}

}

int User::selectProcessorOption()
{
	int option;
	std::cout << "*******************************" << std::endl;
    std::cout << " Processor Menu" << std::endl;
    std::cout << " 1. Normalization" << std::endl;
	std::cout << " 2. Echo" << std::endl;
    std::cout << " 3. Gain adjustment" << std::endl;
    std::cout << "*******************************" << std::endl;
    std::cin >> option;
	return option;
}

std::string User::getOutputFilename()
{
	std::string filename;
	std::cout << " Output Filename?" << std::endl;
    std::cin >> filename;
	return filename;
}


Wav User::process(int process)
{
	Processor proc = Processor();

	switch (process)
	{
	case 1:
		std::cout << "Applying normalization..." << std::endl;
		return proc.normalization(*input);
		break;
	case 2:
		//get params from user
		std::cout << "Applying echo..." << std::endl;
		//return proc.echo(*input);
		break;
	case 3:
		double scale;
		std::cout << "Enter scale factor:";
		std::cin >> scale;
		std::cout << "Adjusting gain..." << std::endl;
		return proc.gainAdjust(*input, scale);
		break;
	default:
		std::cout << "Please enter a valid option";
		break;
	}
}