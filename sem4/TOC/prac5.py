# Program for generating strings of regular expression: 1 (0+1)* 0

import itertools


def generate_strings(max_length=5):
    valid_strings = []

    # Generate possible middle sequences of '0' and '1'
    for length in range(max_length):  # Length of middle part (0+1)*
        for middle in itertools.product("01", repeat=length):
            string = "1" + "".join(middle) + "0"
            valid_strings.append(string)

    return valid_strings


def is_valid_string(user_input):
    if len(user_input) < 2:  # Minimum length is 2 (e.g., "10")
        return False
    if (
        user_input[0] != "1" or user_input[-1] != "0"
    ):  # Must start with '1' and end with '0'
        return False
    for char in user_input[1:-1]:  # Check that the middle part contains only '0' or '1'
        if char not in "01":
            return False
    return True


# Generate and print valid strings
language_strings = generate_strings(max_length=4)
print("Generated valid strings:", language_strings)

while True:
    user_input = input(
        "\nEnter a string to check (or type 'quit' or 'exit' to stop): "
    ).strip()

    if user_input.lower() in ("quit", "exit"):
        print("Exiting the program.")
        break  # Exit loop

    if is_valid_string(user_input):
        print(f" '{user_input}' matches the regular expression.")
    else:
        print(f" '{user_input}' Does not matches the regular expression.")
