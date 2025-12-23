#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(const char *word)
{
    if (strlen(word) == 0)
        return false;

    for (int i = 0; word[i] != '\0'; i++)
    {
        if (!isdigit(word[i]))
        {
            return false;
        }
    }
    return true;
}

char rotate(char c, int n) {
    int key = n;

    if (isupper(c)) {
        return (c - 'A' + key) % 26 + 'A'; // c - 'A' convert ascii to 0-25 range 
    } else if (islower(c)) {                // key rotates the letter
        return (c - 'a' + key) % 26 + 'a'; // + A converts back to ascii
    } else {
        return c;
    }
}


int main(int argc, char const *argv[])
{
    string plaintext, ciphertext;

    if (argc != 2 || !only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int key = atoi(argv[1]);

    plaintext = get_string("plaintext: ");

    printf("ciphertext: ");
    for (int i = 0; i < strlen(plaintext); i++)
    {
        char new_text = rotate(plaintext[i], key);
        printf("%c", new_text);
    }
    printf("\n");


    return 0;
}
