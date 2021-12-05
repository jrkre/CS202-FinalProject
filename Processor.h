/**
 * This header file deals with the processing aspects of the project
 * The processors used on the Wav are normalization, echo, and gain adjustment
 */
#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Wav.h"

class Processor {

    int startOfFile = 44;

public:

    Wav normalization(Wav &input);
    Wav echo(Wav input);
    Wav gainAdjust(Wav &input, double scaleFactor);


};


#endif