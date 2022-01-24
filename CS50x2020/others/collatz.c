#include <stdio.h>
#include <cs50.h>

int collatz(int n);

int main(void)
{
    int n = get_int("Please insert a positive integer: ");
    int steps = collatz(n);
    printf("%i\n", steps);
}

int collatz(int n)
{

    //base case
    if (n == 1)
    {
        return 0;
    }

    //recursive functions
    else if ((n % 2) == 0)
    {
        return 1 + collatz(n/2);
    }
    else
    {
        return 1 + collatz(3*n + 1);
    }

}

