#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <cs50.h>

int main(int argc, char *argv[])
{

    //Check for correct number of arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }


    //Open memory card for reading
    //file is our inputfile i.e. the memory card
    FILE *file = fopen(argv[1], "r");

    //Check if able to open file
    if (file == NULL)
    {
        printf("File not found\n");
        return 1;
    }

    //Block
    uint8_t buffer[512];
    //File name size (e.g 000.jpg'\0)
    char filename[8];
    //ptr to output file
    FILE *outputFile;
    //counter for num of jpegs found
    int counter = 0;


    bool isJpegFound = False;

    //Loop through memory card
    //Stop when fread is False (0)
    while (fread(buffer, 512, 1, file) != 0)
    {
        //Read buffer
        //Look for begining of a JPEG file
        //JPEG IS FOUND
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //JPEG is found: do this
            //open a new JPEG file
            //write 512 bytes until new JPEG is found
            isJpegFound = True;
            //Create new file of size fileNameSize with name of counter
            sprint(filename, "%03i.jpg", counter);
            outfile = fopen(filename, "w");
            counter++;
            if (outfile == NULL)
            {
                fclose(outfile);
                return 1;
            }
            fwrite(buffer, 512, 1, outputFile);



        }
        if(file == NULL)
        {
            fclose(file);
        }
        if(outfile == NULL)
        {
            fclose(outfile);
        }

        //NOJPEG IS FOUND
        else
        {
            isJpegFound = False;
        }



    }



    //Closing memory card (stop reading)
    fclose(file);
    return 0;
}

