#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;

    //Getting input from the user
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    //Converting change due from dollars to cents
    int cents = round(change * 100);

    int changeDue = cents;
    int totalCoins = 0;

    //Comparing value of changeDue to coin
    //Calculating number of coins needed
    while (changeDue >= 25)
    {
        changeDue = changeDue - 25;
        totalCoins = totalCoins + 1;
    }
    while (changeDue >= 10)
    {
        changeDue = changeDue - 10;
        totalCoins = totalCoins + 1;
    }
    while (changeDue >= 5)
    {
        changeDue = changeDue - 5;
        totalCoins = totalCoins + 1;
    }
    while (changeDue >= 1)
    {
        changeDue = changeDue - 1;
        totalCoins = totalCoins + 1;
    }

    printf("%i\n", totalCoins);




}