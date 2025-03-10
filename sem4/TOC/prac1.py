# Implement a DFA to accept a language with three consecutive ones.


def dfa(s):
    state = 0

    for char in s:
        if state == 0:
            state = 1 if char == "1" else 0
        elif state == 1:
            state = 2 if char == "1" else 0
        elif state == 2:
            state = 3 if char == "1" else 0
        elif state == 3:
            state = 3
    return state == 3


def menu():
    while True:
        input_string = (
            input("Enter a binary string (or type 'exit' to quit): ").strip().lower()
        )

        if input_string == "exit":
            print("Exiting the program...!")
            break

        if all(char in "01" for char in input_string):
            result = "Accepted" if dfa(input_string) else "Rejected"
            print(f"String: {input_string} -> {result}")
        else:
            print(
                "Invalid input! Please enter a binary string containing only 0 and 1."
            )


menu()


##########################################################################
def dfa(s):
    # Define the states
    state = 0

    # Transition function
    for char in s:
        if state == 0:
            state = 1 if char == "1" else 0
        elif state == 1:
            state = 2 if char == "1" else 0
        elif state == 2:
            state = 3 if char == "1" else 0
        elif state == 3:
            state = 3  # Once in accepting state, remain there.

    # Accept if the final state is the accepting state
    return state == 3


while True:
    input_string = input("Enter a binary string (or type 'exit' to quit): ")

    if input_string.lower() == "exit":
        print("Exiting the program...!")
        break

    if all(char in "01" for char in input_string):
        result = "Accepted" if dfa(input_string) else "Rejected"
        print(f"String: {input_string} -> {result}")
    else:
        print("Invalid input! Please enter a binary string containing only 0 and 1.")
