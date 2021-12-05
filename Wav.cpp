#include "Wav.h"


Wav::Wav(){}

Wav::Wav (const std::string &fileName, const std::string &newFileName)
{
    Wav::fileName = fileName;
    Wav::newFile = newFileName;
    readFile(fileName);
}

Wav::Wav(std::string filename, wavheader h, unsigned char *buffer)
{
    Wav::fileName = fileName;
    Wav::header = h;
    Wav::buffer = buffer;
}

Wav::Wav(Wav w, unsigned char *b)
{
    header = w.header;
    buffer = b;
    fileName = w.fileName;
    newFile = w.newFile;

}

int Wav::getDataBytes()
{
    return header.data_bytes;
}

wavheader Wav::getHeader()
{
    return Wav::header;
}

std::string Wav::getFilename()
{
    return fileName;
}

unsigned char* Wav::getBuffer()
{
    return buffer;
}

std::string Wav::getNewFName()
{
    return newFile;
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


wavheader readHeader(std::ifstream &file) {
    wavheader header;
    file.read((char*) &header.riff_header, 4);
    std::string riff_header(header.riff_header, 4);
    if (riff_header != "RIFF") {
        std::cout << "Not a RIFF file" << std::endl;
        exit(1);
    }
    file.read((char*) &header.wav_size, 4);
    file.read((char*) &header.wave_header, 4);
    std::string wave_header(header.wave_header, 4);
    if (wave_header != "WAVE") {
        std::cout << "Not a WAVE file" << std::endl;
        exit(1);
    }
    file.read((char*) &header.fmt_header, 4);

    std::string fmt_header(header.fmt_header, 4);
    if (fmt_header != "fmt ") {
        std::cout << "Not a fmt file" << std::endl;
        exit(1);
    }
    file.read((char*) &header.fmt_chunk_size, 4);
    file.read((char*) &header.audio_format, header.fmt_chunk_size);

    file.read((char*) &header.data_header, 4);
    std::string data_header(header.data_header, 4);
    if (data_header != "data") {
        std::cout << "Not a data file" << std::endl;
        exit(1);
    }
    file.read((char*) &header.data_bytes, 4);


    return header;


//    if(strcmp(header.riff_header, "RIFF") != 0){
//        std::cout << "Not a valid wav file" << std::endl;
//        exit(1);
//    }

}


void Wav::readFile(const std::string &fileName)
{
    Wav::fileName = fileName;
    std::ifstream file(fileName, std::ios::binary | std::ios::in);
    if (file.is_open()) {
        /* wavheader openHeader;        
        file.read((char*) &openHeader, sizeof(openHeader));
        Wav::header = openHeader; */
        Wav::header = readHeader(fileName);
        Wav::buffer = new unsigned char[Wav::header.data_bytes];
        file.read((char*) buffer, Wav::header.data_bytes);
        file.close();


        //lancaster showed this line - im not entirely sure what it's doing
        //but it could be relevant to the audio processing and the little endian stuff
        //auto* shortBuffer = reinterpret_cast<char*>(Wav::buffer);
    }
}


void Wav::saveFile() 
{
    std::ofstream file(newFile, std::ios::binary | std::ios::out);

    /*char* headerToWrite[sizeof(wavheader)];
    std::memcpy(headerToWrite, &Wav::header, sizeof(wavheader));

    char* headerForFile = (char*)(&Wav::header);*/
    auto* shortBuffer = reinterpret_cast<char*>(Wav::buffer);

    //file.write(headerForFile, sizeof(Wav::header));
    file.write(shortBuffer, header.data_bytes + 44);
    
    file.close();

}




