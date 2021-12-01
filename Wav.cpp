#include "Wav.h"


Wav::Wav()
{

}

Wav::Wav (const std::string &fileName)
{
    Wav::fileName = fileName;
    *header = readHeader(fileName);
    readFile(fileName);
}


wavheader& Wav::getHeader()
{
    return *header;
}

wavheader Wav::readHeader(const std::string &fileName)
{
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    wavheader header;
    if (file.is_open()) {
        file.read(( char*) &header, sizeof(header));
        file.close();
    }
    return header;
}




void Wav::readFile(const std::string &fileName){
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if (file.is_open()) {
        auto header = readHeader(fileName);
        auto buffer = new unsigned char[header.data_bytes];
        file.read(( char*) buffer, header.data_bytes);
        file.close();
    }
}


