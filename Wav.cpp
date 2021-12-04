#include "Wav.h"


Wav::Wav()
{

}


Wav::Wav (const std::string &fileName, const std::string &newFileName)
{
    Wav::fileName = fileName;
    Wav::newFile = newFileName;
    readFile(fileName);
}



int Wav::getHeaderDB()
{
    return header.data_bytes;
}



unsigned char* Wav::getBuffer()
{
    return buffer;
}


wavheader Wav::readHeader(const std::string &fileName)
{
    Wav::fileName = fileName;
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    wavheader myheader;
    if (file.is_open()) {
        file.read(( char*) &myheader, sizeof(myheader));
        file.close();
    }
    return myheader;
}


void Wav::readFile(const std::string &fileName)
{
    Wav::fileName = fileName;
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if (file.is_open()) {
        auto openHeader = readHeader(fileName);
        headerCopy = openHeader;
        Wav::header = openHeader;
        Wav::buffer = new unsigned char[openHeader.data_bytes];
        file.read((char*) buffer, openHeader.data_bytes);
        file.close();


        //lancaster showed this line - im not entirely sure what it's doing but it could be relevant to the audio processing and the little endian stuff
        //auto* shortBuffer = reinterpret_cast<short*>(Wav::buffer);
    }
}


void Wav::printBuffer() 
{
    std::ofstream file(newFile, std::ios::binary | std::ios::out);

    auto* shortBuffer = reinterpret_cast<char*>(Wav::buffer);

    file.write(shortBuffer, headerCopy.data_bytes);
    
}




