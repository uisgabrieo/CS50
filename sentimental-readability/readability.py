from cs50 import get_string
import re


def count_letter(text: str) -> int:
    valid_letters = r"[a-zA-Z]"
    count = 0
    for letter in text:
        if (re.match(valid_letters, letter)):
            count += 1
    return count


def count_word(text: str) -> int:
    count = 0
    if (text == ""):
        return count
    count += 1
    for letter in text:
        if (letter.isspace()):
            count += 1
    return count


def count_setences(text: str) -> int:
    sentence = r"[!?.]"
    count = 0
    for letter in text:
        if (re.match(sentence, letter)):
            count += 1
    return count


def calculate_grade(letter: int, word: int, setences: int) -> int:
    L = (letter/word) * 100
    S = (setences/word) * 100

    index_grade = round(0.0588 * L - 0.296 * S - 15.8)

    return int(index_grade)


if (__name__ == "__main__"):
    text = get_string("Text: ")

    letter = count_letter(text)
    word = count_word(text)
    setences = count_setences(text)

    grade = calculate_grade(letter, word, setences)

    if (grade < 1):
        print("Before Grade 1")
    elif (grade <= 16):
        print(f"Grade {grade}")
    else:
        print("Grade 16+")
