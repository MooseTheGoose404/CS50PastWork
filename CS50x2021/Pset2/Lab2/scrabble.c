#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("its  a tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;

    //itterates through each char of word
    for (int i = 0; i < strlen(word); i++)
    {
        //checks if is upper then takes index and assigns point
        if (isupper(word[i]))
        {
            //0 index upper alphabet
            int index = word[i] - 65;
            score = score + POINTS[index];
        }
        //checks if is lower then takes index and assigns point
        if (islower(word[i]))
        {
            //0 index lower alphabet
            int index = word[i] - 97;
            score = score + POINTS[index];

        }

    }
    return score;
}