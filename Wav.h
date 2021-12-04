#ifndef WAV_H
#define WAV_H
#include <vector>
#include <iostream>
#include <fstream>
#include "wavheader.h"

class Wav {
private:
    std::string fileName;
    std::string newFile;
    wavheader header;
    wavheader headerCopy;
    unsigned char *buffer;

public:

    /**
     * Default constructor
     */
    Wav();


    /**
     * Constructor that will instantiate a full Wav class from filename
     */
    Wav(const std::string &fileName, const std::string &newFileName);
    

    /**
     * 
     * Constructor that will take the neccessary data and form a new file
     * that can be saved to the filesystem
     * 
     */
    Wav(std::string filename, wavheader h, unsigned char *buffer);

    
    /**
     * readHeader() will read the contents of the header of the file and return them as a struct
     */
    wavheader readHeader(const std::string &fileName);


    /**
     * readFile() will read the contents of the file and put them in the buffer.
     */
    void readFile(const std::string &fileName);


    int getHeaderDB();

    unsigned char* getBuffer();

    //this function is just a sanity check
    void printBuffer();

    /**
     * 
     * verifyHeader() is a verification that the format of the header is accurate
     * 
     */
    bool verifyHeader();
    

    /**
     * 
     * saveFile() will save the file to the project folder with
     * @param newFilename
     * 
     */
    void saveFile(std::string &newFilename);

};


#endif
