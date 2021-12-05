/**
 * This header file deals with the file entered by the user and takes necessary data from it to form the
 * Wav class 
 */
#ifndef WAV_H
#define WAV_H
#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include "wavheader.h"

class Wav {
private:
    std::string fileName;
    
    //this is a workaround - should fix this at some point
    std::string newFile;

    wavheader header;
    unsigned char *buffer;

public:

    /**
     * Default constructor
     */
    Wav();


    /**
     * Constructor that will instantiate a full Wav class from filename
     * @param fileName - filename entered by user used to instantiate Wav class
     */
    Wav(const std::string &fileName);
    

    /**
     * 
     * Constructor that will take the neccessary data and form a new file
     * that can be saved to the filesystem
     * @param filename - filename entered by user 
     * @param h - 
     * @param buffer -
     */
    Wav(std::string filename, wavheader h, unsigned char *buffer);


    /**
     * 
     * Construct a new Wav object from an existing wav and a new buffer
     * 
     * @param w 
     * @param buffer 
     */
    Wav(Wav w, unsigned char *buffer);
    
    /**
     * readHeader() will read the contents of the header of the file and return them as a struct
     * @param fileName - filename entered by user
     */
    wavheader readHeader(const std::string &fileName);


    /**
     * readFile() will read the contents of the file and put them in the buffer.
     * @param fileName - filename entered by user
     */
    void readFile(const std::string &fileName);

    void setOutFileName(const std::string &filename);

    int getDataBytes();

    wavheader getHeader();

    unsigned char* getBuffer();

    std::string getFilename();

    std::string getNewFName();

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
    void saveFile();

};


#endif
