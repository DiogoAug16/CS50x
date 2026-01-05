from cs50 import get_string
import math

def letters_count(text):
    letters = 0
    for char in text:
        if char.isalpha():
            letters += 1
    return letters


def words_count(text):
    words = 1
    for char in text:
        if char.isspace():
            words += 1
    return words


def sentences_count(text):
    sentences = 0
    for char in text:
        if char in ".!?":
            sentences += 1
    return sentences


def grade_level(avg_letters, avg_sentences):
    return (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8


def main():
    text = get_string("Text: ")

    letters = letters_count(text)
    words = words_count(text)
    sentences = sentences_count(text)

    avg_letters = (letters / words) * 100
    avg_sentences = (sentences / words) * 100

    index = round(grade_level(avg_letters, avg_sentences))

    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()
