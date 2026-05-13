def main():
    name = input("What is your name? ")  # asking for input
    hello(name)  # calling hello function with input as name


def hello(s):
    print(f"hello, {s}")  # prints hello with user input


main()
