#ifndef PROCESSOR_H
#define PROCESSOR_H
#include "Wav.h"

class Processor {


public:

    Wav normalization(Wav input);
    Wav echo(Wav input);
    Wav gainAdjust(Wav input);


};


#endif