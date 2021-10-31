#include "FileIO.h"
#include <fstream>

void FileIO::readFile(const std::string &filenname)
{
    std::ifstream file(filename, std::ios::binary | std::ios::in);
    if (file.is_open())
    {
        file.read((char*) &Wav::header, sizeof(wavheader));
        buffer = new unsigned char [wavheader.data_Bytes];
    }
}