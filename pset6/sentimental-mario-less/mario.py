def main():
    while True:  # while loop to get the user input within the range
        try:
            height = int(input("Height: "))
        except ValueError:  # catching the value error to reprompt the user
            continue
        if height >= 1 and height <= 8:
            break
    print_mario(height)  # calling the function to print mario


def print_mario(n):  # function to print mario
    for i in range(n):
        for j in range(0, n-i-1):
            print(" ", end="")
        for j in range(0, i + 1):
            print("#", end="")
        print()


main()
