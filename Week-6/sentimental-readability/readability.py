from cs50 import get_string


def main():

    text = get_string("Text: ")

    # Functions Calling
    words = words_function(text)
    letters = letters_function(text)
    sentences = sentences_function(text)

    # Coleman-Liau index
    L = letters / words * 100
    S = sentences / words * 100
    index = 0.0588 * L - 0.296 * S - 15.8

    # Condionals
    if index > 16:
        print("Grade 16+")
    elif index < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(index)}")


def words_function(t):
    count = 1
    for _ in t:
        if _ == " ":
            count += 1
    return count


def letters_function(t):
    count = 0
    for _ in t:
        if 'a' <= _ <= 'z' or 'A' <= _ <= 'Z':
            count += 1
    return count


def sentences_function(t):
    count = 0
    for _ in t:
        if _ == "." or _ == "!" or _ == "?":
            count += 1
    return count


main()
