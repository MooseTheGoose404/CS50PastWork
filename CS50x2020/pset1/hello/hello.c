#include <stdio.h>
#include <cs50.h>

int main(void) 
{
    //Asks for user's name
    string name = get_string("What's your name?\n");
    //Says hello to user!
    printf("Hello, %s!\n", name);
}