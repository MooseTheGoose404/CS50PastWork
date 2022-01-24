#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool check_valid_key(string s);


int main(int argc, string argv[])
{
    //Checking for valid command line arguments

    if (argc != 2 || !check_valid_key(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Converts key into int
    int key = atoi(argv[1]);

    //Getting plaintext from the user
    string plaintext = get_string("plaintext: ");

    //Converting to ciphertext then printing it
    printf("ciphertext: ");
    int length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        char character = plaintext[i];
        if (isalpha(character))
        {
            char mod = 'A';
            if (islower(character))
            {
                //converting plaintext to ciphertext
                mod = 'a';
            }
                printf("%c", (character - mod  + key) % 26 + mod);


        }
        else
        {
            printf("%c", character);
        }

    }

    printf("\n");

    return 0;

}

bool check_valid_key(string s)
{
    //iterates threw each letter of plaintext and checks if digit
    for (int i = 0, length = strlen(s); i < length; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
