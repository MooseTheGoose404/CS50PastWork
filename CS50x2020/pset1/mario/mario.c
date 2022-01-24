#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    //Prompts user for height until valid value is given
    do
    {
        height = get_int("Choose a height from 1-8: ");
    }
    while (height < 1 || height > 8);

    int tagsInRow = 1;
    int spacesInRow = (height - tagsInRow);

    //Outmost loop: Will repeat loop height times
    //i.e. the number of rows will be equal to the height
    for (int j = 0; j < height; j++)
    {

        //This loop adds spaces to set up for a right aligned triangle
        for (int i = 0; i < spacesInRow; i ++)
        {
            printf(" ");
        }
        //This loop prints tags for the right aligned triangle
        for (int l = 0; l < tagsInRow; l++)
        {
            printf("#");
        }

        //Spaces in between both triangles
        printf("  ");

        //This loop prints tags for the left aligned triangle
        for (int p = 0; p < tagsInRow; p++)
        {
            printf("#");
        }

        //For every spacesInRow decreases by one as tagsInRow increases by one
        spacesInRow --;
        tagsInRow ++;
        printf("\n");


    }



}