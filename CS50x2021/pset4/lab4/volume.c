// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);
    
    //Array of bytes for header
    uint8_t header[44];
    
    //Use fread() to read data into header array
    fread(&header, 44, 1, input);
    
    //Write data from header array to new file
    fwrite(&header, 44, 1, output);

    // TODO: Read samples from input file and write updated data to output file
    //Repeat through each sample:
    //Read sample -> multiply by volume -> write to output 
    int16_t buffer; 
    while (fread(&buffer, 2, 1, input))
    {
        buffer = buffer * factor;
        fwrite(&buffer, 2, 1, output);
    }
    
    

    // Close files
    fclose(input);
    fclose(output);
}
