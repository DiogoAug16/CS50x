#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

bool invalid_type(string word){
    if (strlen(word) == 0)
        return true;

    for (int i = 0; word[i] != '\0'; i++){
        if (isdigit(word[i]))
            return true;
    }

    return false;
}

int player_score(string word) {
    int points[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    int score = 0;

    for (int i = 0; word[i] != '\0'; i++) {
        if (isupper(word[i])) {
            score += points[word[i] - 'A'];
        } else if (islower(word[i])) {
            score += points[word[i] - 'a'];
        }
    }

    return score;
}

int main(int argc, char const *argv[])
{
    string word1, word2;
    int score1, score2;
    /* code */
    do {
        word1 = get_string("Player 1: ");
        word2 = get_string("Player 2: ");
    } while (invalid_type(word1) || invalid_type(word2));

    if (player_score(word1) > player_score(word2)) {
        printf("Player 1 wins!\n");
    } else if (player_score(word1) < player_score(word2)) {
        printf("Player 2 wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}
