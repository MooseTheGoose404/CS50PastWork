#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    //get height from user
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    int spacesOnRow = height - 1;
    int hashesOnLeft = 1;
    int hashesOnRight = 1;

    //loop repeats for each row of pyramid
    for (int j = 0; j < height; j++)
    {
        //loop to print the beginning spaces
        for (int i = 0; i < spacesOnRow; i++)
        {
            printf(" ");
        }
        spacesOnRow--;

        //loop to print the left hashes
        for (int i = 0; i < hashesOnLeft; i++)
        {
            printf("#");
        }
        hashesOnLeft++;

        printf("  ");

        //loop to print the right hashes
        for (int i = 0; i < hashesOnRight; i++)
        {
            printf("#");
        }
        hashesOnRight++;

        printf("\n");
    }





}