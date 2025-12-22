#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int letters_count(string text) {
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isalpha(text[i])) {
            letters++;
        }
    }
    return letters;
}

int words_count(string text) {
    int words = 1;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (isspace(text[i])) {
            words++;
        }
    }
    return words;
}

int sentences_count(string text) {
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    return sentences;
}

float grade_level(float AVGNumberOfWords, float AVGNumberOfSentences) {
    float level = (0.0588 * AVGNumberOfWords) - (0.296 * AVGNumberOfSentences) - 15.8;
    return level;
}

int main(int argc, char const *argv[])
{
    /* code */
    string text;
    int letters, words, sentences, index;
    float AVGNumberOfWords, AVGNumberOfSentences;

    text = get_string("Text: ");
    letters = letters_count(text);
    words = words_count(text);
    sentences = sentences_count(text);

    AVGNumberOfWords = ((float) letters / words) * 100;
    AVGNumberOfSentences = ((float) sentences / words) * 100;

    index = round(grade_level(AVGNumberOfWords, AVGNumberOfSentences));

    // printf("Letters: %d\n", letters);
    // printf("Words: %d\n", words);
    // printf("Sentences: %d\n", sentences);

    if (grade_level(AVGNumberOfWords, AVGNumberOfSentences) < 1 ) {
        printf("Before Grade 1\n");
    } else if (grade_level(AVGNumberOfWords, AVGNumberOfSentences) >= 16 ) {
        printf("Grade 16+\n");
    } else {
        printf("Grade %d\n", index);
    }

    return 0;
}
