# Implement a DFA to accept a decimal number divisible by 2


def dfa(s):
    state = 0

    for char in s:
        if char.isdigit():
            digit = int(char)
            state = 0 if digit % 2 == 0 else 1
        elif char == ".":
            continue
        else:
            return False

    return state == 0


def menu():
    while True:
        input_string = (
            input("Enter a number (or type 'quit' to exit): ").strip().lower()
        )

        if input_string == "quit":
            print("Exiting the program...!")
            break

        if all(char.isdigit() or char == "." for char in input_string):
            result = "Divisible By 2" if dfa(input_string) else "Not Divisible By 2"
            print(f"Number: {input_string} -> {result}")
        else:
            print("Invalid input! Please enter a valid number.")


menu()
