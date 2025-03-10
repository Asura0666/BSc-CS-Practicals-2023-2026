# Program for generating strings of regular expression: (0+1)*  10 (0+1)*

import itertools


def generate_strings(max_length):
    valid_strings = []
    for length1 in range(max_length):  # Length of the prefix
        for length2 in range(max_length):  # Length of the suffix
            for prefix in itertools.product("01", repeat=length1):
                for suffix in itertools.product("01", repeat=length2):
                    string = "".join(prefix) + "10" + "".join(suffix)
                    valid_strings.append(string)
    return valid_strings


def is_valid_string(user_input):
    if "10" not in user_input:
        return False
    for char in user_input:
        if char not in "01":
            return False
    return True


max_length = 4
language_strings = generate_strings(max_length)
print("Generated valid strings:", language_strings)

while True:
    user_input = input(
        "\nEnter a string to check (or type 'quit' or 'exit' to stop): "
    ).strip()
    if user_input.lower() in ("quit", "exit"):
        print("Exiting the program.")
        break
    if is_valid_string(user_input):
        print(f'"{user_input}" matches the regular expression.')
    else:
        print(f'"{user_input}" does not match the regular expression.')
