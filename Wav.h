//
// Created by jrkre on 10/28/21.
//

#ifndef WAV_H
#define WAV_H
#include <vector>
#include <iostream>
#include <fstream>
#include "wavheader.h"

class Wav {
    std::string filename;
    wavheader* header;


    public:
    
    void readFile(const std::string &filenname);
    unsigned char *buffer;

    wavheader& getHeader();
    

};


#endif
