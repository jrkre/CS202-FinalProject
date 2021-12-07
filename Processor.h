/**
 * This header file deals with the processing aspects of the project.
 * The processors used on the Wav are normalization, echo, and gain adjustment
 */
#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Wav.h"

class Processor {

    int startOfFile = 0;

public:

/**
 * echo will copy and scale samples to add them at later points and create the echo effect
 * @param input - input from file info.
 * @param delay - the delay 
 * @param gain - the gain
 */
    Wav echo(Wav &input, int delay, float gain);
/**
 * normalization will scale the data so the largest sample value is the maximum possible value
 * @param input - input from file info.
 */
    Wav normalization(Wav &input);
/**
 * gainAdjust will multiply samples by a scaling factor that raises or lowers the overall amplitude of the
 * Wav file.
 * @param input - input from file info.
 * @param scaleFactor - the scaling factor
 */
    Wav gainAdjust(Wav &input, double scaleFactor);


};


#endif
