def main():
    while True:  # while loop to sanitize the output according to needs
        try:
            change = float(input("Change: "))
        except ValueError:
            continue
        if change >= 0:
            break
    change = convert_cents(change)
    calculator(change)


def convert_cents(x):  # function that converts dollars into cents
    return x * 100


def calculator(x):  # function to calculate the minimum number of coins reqd. uses greedy algorithm
    count = 0
    while True:  # loop runs and counts the min no of coins reqd by checking from 25, 10, 5, 1
        count += 1
        if x >= 25:
            x -= 25
        elif x >= 10:
            x -= 10
        elif x >= 5:
            x -= 5
        elif x >= 1:
            x -= 1
        else:
            break
    print(count-1)  # prints the count, -1 bcos it counts the else as well

main()
