#include <cs50.h>
#include <stdio.h>

int fact(int n);

int main(void)
{
    int n = get_int("Please enter a positive integer: ");
    printf("%i\n", fact(n));

}

int fact(int n)
{
//Base case
if (n == 1)
    return 1;
//Recursive case
else
    return n * fact(n-1);

}
