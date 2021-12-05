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
int main(int argc, char *argv[]) {

	User user = User();

	user.initialOptions();

	user.fileOptions();	
	return 0;
} 
