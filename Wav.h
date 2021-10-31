//
// Created by jrkre on 10/28/21.
//

#ifndef WAV_H
#define WAV_H
#include <vector>
#include <iostream>
#include "wavheader.h"

class Wav {
    std::string filename;
    wavheader * header;


    public:
    
    &wavheader getHeader()
    {
        return &wavheader
    }

};


#endif
