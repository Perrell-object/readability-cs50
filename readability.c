#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void determine_count(string input);
int grade_level(float letter, float word, float sent);

//initialized variable to be used by all functons
float letter_count = 0;
float word_count = 0;
float sent_count = 0;

int main(void)
{
    //get text from the user
    string text_input = get_string("Type text here: ");
    determine_count(text_input);
    int grade = grade_level(letter_count, word_count, sent_count);
    if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

//put user input through loop to calculate letter, word, and sentence count
void determine_count(string input)
{
    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (isalnum(input[i]))// check if alphanumeric values
        {
            letter_count++;
        }
        else if (isblank(input[i]))//checks for spaces
        {
            word_count++;
        }

        //checks punctuation to determine word cound and sentence count
        else if ((input[i] == 46 || input[i] == 33 || input[i] == 63) && i == n - 1)
        {
            word_count++;
            sent_count++;
        }
        else if (input[i] == 46 || input[i] == 33 || input[i] == 63) //checks punctuation before last index of string
        {
            sent_count++;
        }
    }

}

//passing all variables to determine the grade level
int grade_level(float letter, float word, float sent)
{
    return round(0.0588 * ((100 / word_count) * letter_count) - 0.296 * ((100 / word_count) * sent_count) - 15.8);
}