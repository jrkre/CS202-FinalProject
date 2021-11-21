#ifndef FILEIO_H
#define FILEIO_H

#include <iostream>
#include "wavheader.h"
#include "Wav.h"


class FileIO{

std::string filename;

public:
    void readFile(const std::string &filenname);

    unsigned char buffer [];
};

#endif