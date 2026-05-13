def main():
    number = input("Number: ")
    card_validator(number)


def card_validator(number):  # validates the card and prints the type of card
    length = len(number)
    skip = True
    total = 0
    for i in reversed(range(length)):  # loop goes in reverse to test using Luhns algorithm
        if skip:  # uses skip bool variable to skip value from reversed order
            total += int(number[i])
            skip = False
            continue
        else:
            x = int(number[i]) * 2
            if x >= 10:
                total += x % 10
                x = int(x / 10)
            total += x % 10
            skip = True
    if total % 10 != 0:
        print("INVALID")  # as per luhns algo if it doesnt end with zero its not valid

    if length == 15 and number[0:2] in ["34", "37"]:  # check condition for american express card
        print("AMEX")
    elif length == 16 and number[0:2] in ["51", "52", "53", "54", "55"]:  # check condition for mastercard
        print("MASTERCARD")
    elif (length == 13 or length == 16) and number[0] == "4":  # checks condition for visa card
        print("VISA")
    else:
        print("INVALID")


main()
