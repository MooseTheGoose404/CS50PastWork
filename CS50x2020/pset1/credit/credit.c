#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    long creditNumber = 0;
    int creditLength = 0;


    //Getting credit card number from user
    do
    {
        creditNumber = get_long("Number: ");

    } while (creditLength < 0);
    
    long creditNumCounter = creditNumber;
    
    
    //Getting length of the credit card number
    do 
    {
        creditLength++;
        creditNumCounter = creditNumCounter / 10;
    } while (creditNumCounter > 0);
    
    long creditDigitFinder = creditNumber;

    int counter = 1;

    //Finding digits

        int power = creditLength - counter;
        int divider = pow(10, power);
        printf("%i", divider);
        int lastDigit = creditNumber % divider;
        printf("%i", lastDigit);
        
    






}