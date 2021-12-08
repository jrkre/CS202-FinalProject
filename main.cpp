#include <iostream>
#include <memory>
#include "Wav.h"
#include "Processor.h"
#include "user.h"



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

/**
 * Our main runs the user interface
 */
int main(int argc, char *argv[]) {

	User user = User();

	std::string input;
	if (argc > 1) 
	{
		input = argv[1];
	}
	else 
	{
		input = "";
	}
	

	while (user.getStatus())
	{

		user.fileOptions(input);

	}

	return 0;
} 
