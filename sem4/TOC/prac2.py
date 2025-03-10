#Implement a DFA to accept a language ending with 101.	

def is_valid_string(s):
    return all(c in '01' for c in s)

def dfa_accepts(s):
    state = 0  
    for char in s:
        if state == 0:
            state = 1 if char == '1' else 0
        elif state == 1:
            state = 2 if char == '0' else 1
        elif state == 2:
            state = 3 if char == '1' else 0
        elif state == 3:
            state = 1 if char == '1' else 2
    return state == 3

def main():
    print("DFA to check for strings ending with '101' in a binary string.")
    print("Enter 'quit' or 'exit' to exit the program.")
    while True:
        user_input = input("Enter a binary string: ").strip()
        if user_input.lower() in ("quit", "exit"):
            print("Exiting program.")
            break
        elif not is_valid_string(user_input):
            print("Invalid string. Please enter a binary string containing only 0s and 1s.")
        elif dfa_accepts(user_input):
            print("String accepted: Ends with '101'.")
        else:
            print("String rejected: Does not end with '101'.")

if __name__ == "__main__":
    main()