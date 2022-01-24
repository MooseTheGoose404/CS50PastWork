#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);

    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);


    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    int currentSize = startSize;
    int change;


    while (currentSize < endSize)
    {
        currentSize = currentSize + currentSize / 3 - currentSize / 4;
        years++;
    }



    // TODO: Print number of years
    printf("Years: %i\n", years);
}