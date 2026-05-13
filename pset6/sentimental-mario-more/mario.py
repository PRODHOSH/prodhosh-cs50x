def main():
    while True:  # while loop to sanitize the input within 1 and 8
        try:  # using try excpet block to catch value errors and it reprompts
            height = int(input("Height: "))
        except ValueError:
            continue
        if height >= 1 and height <= 8:
            break
    print_mario(height)  # calling the function to print mario based on user input argument


def print_mario(n):  # prints each case in one loop
    for i in range(n):  # outer loop
        for j in range(0, n-i-1):
            print(" ", end="")

        for j in range(0, i+1):
            print("#", end="")

        print("  ", end="")

        for j in range(0, i+1):
            print("#", end="")

        print()


main()
