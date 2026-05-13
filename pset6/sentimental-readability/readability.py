# readability problem with the Coleman-Liau formula

def main():
    text = input("Text: ")  # gets the input from user
    L, S = calculate(text)  # calls the function to use the user input and calculate L, S
    index = coleman_liau(L, S)  # this function has the formula with it
    print_grade(index)  # calls the function that prints the grade


def calculate(s):  # calculates the count of letters, words, sentences and finds L, S
    count_sentences = 0
    count_letters = 0
    count_words = 0
    for i in range(len(s)):
        if s[i] in ["?", "!", "."]:
            count_sentences += 1
        elif s[i] not in [" ", "\'", ",", "\"", ";", ":"]:
            count_letters += 1
            if s[i+1] in [" ", "!", ".", "?", ",", ";", ":"]:
                count_words += 1
    L = (count_letters / count_words) * 100
    S = (count_sentences / count_words) * 100
    return L, S


def coleman_liau(L, S):  # takes L, S as arguments and returns the formulated index
    return 0.0588 * L - 0.296 * S - 15.8


def print_grade(i):  # prints the grade using the formulated index and handling the cases
    if i >= 16:
        print("Grade 16+")
    elif i <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(i)}")


main()
