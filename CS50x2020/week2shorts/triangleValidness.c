#include <stdio.h>
#include <cs50.h>

bool triangleValidnessVerifier(int a, int b, int c);

int main(void)
{
    printf("Please input each side of the triangle\n");
    int sideA = get_int("");
    int sideB = get_int("");
    int sideC = get_int("");

    bool isTriangleValid = triangleValidnessVerifier(sideA, sideB, sideC);

    if (isTriangleValid == true)
    {
        printf("This triangle is valid!\n");
    }
    else
    {
        printf("This triangle is not valid :-(\n");
    }

}

bool triangleValidnessVerifier(int a, int b, int c)
{
    if ((a || b || c) <= 0)
    {
        return false;
    }
    
    if ((a + b <= c) || (a + c <= b) || (b + c <= a))
    {
        return false;
    }

    else
    {
        return true;
    }
}