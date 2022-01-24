#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int indexCollection[100];
    for (int i = 0; i < 100; i++)
    {
        indexCollection[i] = i;
        printf("%i", indexCollection[i]);
        printf("\n");
    }
}