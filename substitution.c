#include <cs50.h>
#include <stdio.h>
#include<string.h>
#include <ctype.h>

//declared function prototypes
void substitute();
void validate_text(char c, string arg);


int main(int argc, string argv[])
{
    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)

        {
            //iterating over each character of the string
            for (int i = 0; i < strlen(argv[1]); i++)
            {
                //check if key contains non-alhabetical characters
                if (! isalpha(argv[1][i]))
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }
                //comparing the first character to the next character in the iteration to check for repeated characters
                for (int j = i + 1; j < strlen(argv[1]); j++)
                {

                    if (toupper(argv[1][j]) == toupper(argv[1][i]))
                    {
                        printf("Key must not contain repeated alphabets.\n");
                        return 1;
                    }
                }
            }

            substitute(argv[1]);
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

    }
    // print if arguments are less than 2
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    return 0;
}

void substitute(string key)
{
    //get plaintext
    string input = get_string("plaintext: ");
    //print ciphertext
    printf("ciphertext: ");

    for (int i = 0; i < strlen(input); i++)
    {
        // passing arguements to same case
        if (isalpha(input[i]))
        {
            char c = input[i];
            //check if characters from user input is lowercase or uppercase
            if (islower(input[i]))
            {
                validate_text(tolower(c), key);
            }
            else
            {
                validate_text(toupper(c), key);
            }
        }
        else
        {
            printf("%c", input[i]);
        }
    }
    printf("\n");
}

void validate_text(char c, string arg)
{
    //mapping input text to alphabet array
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < strlen(alphabet); i++)
    {
        //comparing the character positions from input with alphabet position
        if (islower(c)) //if character is in lowercase
        {
            if (c == tolower(alphabet[i]))
            {
                printf("%c", tolower(arg[i]));
            }
        }
        else if (isupper(c)) //if character is in uppercase
        {
            if (c == toupper(alphabet[i]))
            {
                printf("%c", toupper(arg[i]));
            }
        }
    }
}