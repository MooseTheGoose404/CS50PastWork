#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

int letter_count(string the_text);
int word_count(string the_text);
int sentence_count(string the_text);
float grade_calc(float L, float S);

int main(void)
{


    //1) Prompt user for string of text
    //Gets the text to be graded from the user
    string text = get_string("Text: ");

    //Counts number of alphabetic characters
    int number_of_letters = letter_count(text);

    //Counts number of words
    int number_of_words = word_count(text);

    //Counts number of sentences
    int number_of_sentences = sentence_count(text);


    //Caluculating L (average number of letters per 100 words)
    float L = (number_of_letters / (float) number_of_words) * 100;

    //Calculating S (average number of sentences per 100 words)
    float S = (number_of_sentences / (float) number_of_words) * 100;

    //Calculating text grade
    float float_grade = grade_calc(L, S);
    int int_grade = round(float_grade);


    //Printing the final grade :D

    if (int_grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (int_grade > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", int_grade);
    }



    return 0;
}



int letter_count(string the_text)
{
    int alphabets = 0;
    for (int i = 0; the_text[i] != '\0'; i++)
    {
        if ((the_text[i] >= 65 && the_text[i] <= 90) || (the_text[i] >= 97 && the_text[i] <= 122))
        {
            alphabets++;
        }
    }

    return alphabets;
}

int word_count(string the_text)
{
    int words = 0;
    for (int i = 0; the_text[i] != '\0'; i++)
    {
        if (the_text[i] == ' ')
        {
            words++;
        }
    }

    words++;
    return words;
}

int sentence_count(string the_text)
{
    int sentences = 0;
    for (int i = 0; the_text[i] != '\0'; i++)
    {
        if (the_text[i] == '.' || the_text[i] == '?' || the_text[i] == '!')
        {
            sentences++;
        }
    }

    return sentences;
}

float grade_calc(float L, float S)
{
    //index = 0.0588 * L - 0.296 * S - 15.8
    float index = index = 0.0588 * L - 0.296 * S - 15.8;
    return index;
}