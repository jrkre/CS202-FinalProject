//
// Created by jrkre on 10/28/21.
//

#include "Wav.h"



wavheader& Wav::getHeader(){
    return *header;
}


void Wav::readFile(const std::string &filename)
{
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (file.is_open())
    {
        file.read((char*) Wav::header, sizeof(wavheader));
        buffer = new unsigned char [Wav::getHeader().data_bytes];
        file.read((char*) buffer, Wav::getHeader().data_bytes);
        file.close();
    }
}
