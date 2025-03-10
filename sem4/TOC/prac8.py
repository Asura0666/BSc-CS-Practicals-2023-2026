# Program for generating derivation for language with equal number of a’s and b’s starting with a.


def is_valid_string(input_string):

    return (
        input_string.count("a") == input_string.count("b")
        and input_string.startswith("a")
        and all(ch in {"a", "b"} for ch in input_string)
    )


def generate_derivation(input_string):
    derivation = ["S"]
    state = "S"

    for char in input_string:
        if state == "S" and char == "a":
            derivation.append("S -> aA")
            state = "A"
        elif state == "A" and char == "b":
            derivation.append("A -> bS")
            state = "S"
        elif state == "S" and char == "b":
            derivation.append("S -> bB")
            state = "B"
        elif state == "B" and char == "a":
            derivation.append("B -> aS")
            state = "S"

    if state == "S":
        derivation.append("S -> ε")

    return derivation


def main():
    print("Grammar: S -> aA | bB | ε, A -> bS, B -> aS")
    print("Terminal: T = {a, b}")
    print("Type 'exit' to quit.\n")

    while True:
        user_input = input("Enter a string over the terminal T = {a, b}: ").strip()

        if user_input.lower() == "exit":
            print("Exiting the program.")
            break

        if is_valid_string(user_input):
            print("\nString is valid.")
            derivation = generate_derivation(user_input)
            print("Derivation Steps:")
            for step in derivation:
                print(step)
        else:
            print(
                "\nInvalid string. The string must start with 'a' and have an equal number of 'a's and 'b's.\n"
            )


if __name__ == "__main__":
    main()
