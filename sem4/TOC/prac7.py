# Program for generating derivation for the given grammar


def is_valid_odd_a(input_string):
    return input_string.count("a") % 2 == 1 and all(ch == "a" for ch in input_string)


def generate_derivation(input_string):
    derivation = ["S"]
    state = "S"
    for char in input_string:
        if state == "S":
            derivation.append(f"{state} -> aA")
            state = "A"
        elif state == "A":
            derivation.append(f"{state} -> aS")
            state = "S"

    if state == "S":
        derivation.append("S -> ε")
    return derivation


def main():
    print("Grammar: S -> aA | ε, A -> aS")
    print("Terminal: T = {a}")
    print("Type 'exit' to quit.\n")

    while True:
        user_input = input("Enter a string over the terminal T = {a}: ").strip()

        if user_input.lower() == "exit":
            print("Exiting the program.")
            break

        if is_valid_odd_a(user_input):
            print("\nString is valid.")
            derivation = generate_derivation(user_input)
            print("Derivation Steps:")
            for step in derivation:
                print(step)
        else:
            print(
                "\nInvalid string. The string must consist only of 'a's and have an odd length.\n"
            )


if __name__ == "__main__":
    main()
