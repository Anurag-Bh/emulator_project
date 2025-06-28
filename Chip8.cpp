#include <fstream>
#include "Chip8.h"
using namespace std;


const unsigned int START_ADDRESS = 0x200;

Chip8::Chip8()
{
	pc = START_ADDRESS;
}

void Chip8::LoadROM(char const* filename) {

    // Open the file as a binary stream and move the pointer to the end to get the file size
    fstream file(filename, ios::binary | ios::ate);
    if(file.is_open()){
        // Get the size of the file and allocate a buffer to hold its contents
        streampos size = file.tellg();
        char* buffer = new char[size];
        
        // Move the file pointer back to the beginning
        file.seekg(0,ios::beg);
        // Read the entire file into the buffer
        file.read(buffer,size);
        // Close the file
        file.close();

        // Copy the buffer contents into the emulator's memory starting at START_ADDRESS
        for(long i = 0; i < size; i++){
            memory[START_ADDRESS + i] = buffer[i];
        }

        // Free the allocated buffer memory
        delete[] buffer;
    }

}



