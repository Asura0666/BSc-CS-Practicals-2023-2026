# Program for tokenization of given input

import re


def tokenize_input(input_text):
    token_pattern = r"[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|[+\-/=<>!]+|[(){}\[\];]"
    tokens = re.findall(token_pattern, input_text)
    return tokens


def validate_tokens(tokens):
    if len(tokens) == 3 and tokens[1] == "=":
        left = tokens[0]
        right = tokens[2]

        if left.isdigit() and right.isdigit():
            return "Error: Constants cannot be assigned to Constants"
        if left.isdigit():
            return "Error: Constant cannot be assigned to an identifier."
    elif len(tokens) < 3:
        return "Error: Invalid input"

    return "Valid"


def main():
    print("Enhanced Tokenization Program")
    print("Type 'quit' or 'exit' to stop:\n")

    while True:
        user_input = input("Enter text to tokenize: ").strip()
        if user_input.lower() in ("quit", "exit"):
            print("Exiting the program...")
            break

        tokens = tokenize_input(user_input)
        validation_result = validate_tokens(tokens)

        print(f"\nTokens: {tokens}")
        print(f"Validation: {validation_result}\n")


if __name__ == "__main__":
    main()
