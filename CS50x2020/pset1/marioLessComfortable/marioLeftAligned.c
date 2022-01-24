#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Prompts user for height until they put in an integer in the range 1-8
    int height;
    do 
    {
        height = get_int("What would you like the height of the pyramid to be? ");
    }  
    while (height < 0 || height > 8);
    
    
    int tagsInRow = 1;
 
    //Prints # equal to tagsInRow then creates a new line
    //Every times the loop repeats tagsInRow increases by 1
    //Both loops stop once loop j has repeated height times
    for (int j = 0; j < height; j++) 
    {
        for (int i = 0; i < tagsInRow; i++) 
        {
        printf("#");
        }
        tagsInRow = tagsInRow + 1;
        printf("\n");
    }
    
}