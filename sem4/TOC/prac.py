//1.three consecutive ones
def dfa(s):

    state=0

    for char in s:
        if state == 0:
            state = 1 if char =='1' else 0
        elif state == 1:
            state = 2 if char =='1' else 0
        elif state == 2:
            state = 3 if char =='1' else 0
        elif state == 3:
            state = 3

    return state == 3

while True:
    input_string=input("Enter a binary string (or type 'exit')")

    if input_string.lower()== 'exit':
        print("Exiting....!")
        break

    if all(char in '01' for char in input_string):
        result="Accepted" if dfa(input_string) else "Rejected"
        print(f"String: {input_string} -->{result}")
    else:
         print("Invalid input")

//2.ending with 101
def dfa (x):

    state = 0

    for char in x:
        if state == 0:
            state = 1 if char == '1' else 0
        elif state == 1:
            state = 2 if char == '0' else 1
        elif state == 2:
            state = 3 if char == '1' else 0
        elif state == 3:
            state = 1 if char == '1' else 2

    return state == 3

while True:
     input_string=input("Enter a binary string(or type 'exit' to quit)")

     if input_string.lower()=="exit":
         print("Exiting...!")
         break

     if all(char in '01' for char in input_string):
          result="Accepted" if dfa(input_string) else "Rejected"
          print(f"String:{input_string} -->{result}")
     else:
          print("Invalid input")

//3.divisible by 2
def is_divisible_by_2(number: str) -> bool:
    q0 = "even"
    q1 = "odd"
    current_state = q0
    for digit in number:
        if digit not in "0123456789":
            raise ValueError("Input must be a valid decimal number.")
        if digit in "02468":
            current_state = q0
        elif digit in "13579":
            current_state = q1
    return current_state == q0

# Main execution loop
while True:
    user_input = input("Enter a decimal number (or type 'exit' to quit): ").strip()
    
    if user_input.lower() == "exit":
        print("Exiting the program.")
        break
    
    try:
        result = is_divisible_by_2(user_input)
        if result:
            print(f"The number {user_input} is divisible by 2.")
        else:
            print(f"The number {user_input} is NOT divisible by 2.")
    except ValueError as e:
        print(f"Error: {e}")

//4.tokenization of given input
import re

def tokenize_input(input_text):
    token_pattern = r"[a-zA-Z_][a-zA-Z0-9_]*|[0-9]+|[+\-/=<>!]+|[(){}\[\];]"
    tokens = re.findall(token_pattern, input_text)
    return tokens

def validate_tokens(tokens):
    if len(tokens) == 3 and tokens[1] == '=':
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
  while True:
        user_input = input("Enter text to tokenize(type 'exit' to stop): ").strip()
        if user_input.lower() in ("exit"):
            print("Exiting the program...")
            break
        
        tokens = tokenize_input(user_input)
        validation_result = validate_tokens(tokens)
        
        print(f"\nTokens: {tokens}")
        print(f"Validation: {validation_result}\n")

if _name== "main_":
    main() 

//5.regular expression 1(0+1)*0
import itertools

def generate_strings(max_length=5):
    valid_strings = []
    
    for length in range(max_length):  # Length of middle part (0+1)*
        for middle in itertools.product("01", repeat=length):
            string = "1" + "".join(middle) + "0"
            valid_strings.append(string)
    
    return valid_strings

def is_valid_string(user_input):
    if len(user_input) < 2:  
        return False
    if user_input[0] != '1' or user_input[-1] != '0':  
        return False
    for char in user_input[1:-1]:  
        if char not in "01":
            return False
    return True

language_strings = generate_strings(max_length=4)
print("Generated valid strings:", language_strings)

while True:
    user_input = input("\nEnter a string to check (or type 'quit' or 'exit' to stop): ").strip()
    
    if user_input.lower() in ("quit", "exit"):
        print("Exiting the program.")
        break  

    if is_valid_string(user_input):
        print(f" '{user_input}' matches the regular expression.")
    else:
        print(f" '{user_input}' Does not matches the regular expression.")

//6.regular expression (0+1)10(0+1)
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
    user_input = input("\nEnter a string to check (or type 'quit' or 'exit' to stop): ").strip()
    if user_input.lower() in ("quit", "exit"):
        print("Exiting the program.")
        break
    if len(user_input) >= 2:  # Minimum length is 2 (e.g., "10")
        if is_valid_string(user_input):
            print(f" '{user_input}' matches the regular expression.")
        else:
            print(f" '{user_input}' Does not matches the regular expression.")
    else:
        print("Inavlid")

//7.generting derivation for the given grammer
def is_valid_odd_a(input_string):
    return input_string.count('a') % 2 == 1 and all(ch == 'a' for ch in input_string)

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
    
    # Final derivation
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
            print("\nInvalid string. The string must consist only of 'a's and have an odd length.\n")

if _name_ == "_main_":
    main()

//8.equal number of a and b starting with a
import re
def is_valid_string(input_string):
    """Check if the string has an equal number of 'a's and 'b's and starts with 'a'."""
    return (
        input_string.count('a') == input_string.count('b')
        and input_string.startswith('a')
        and all(ch in {'a', 'b'} for ch in input_string)
        and re.fullmatch(r'a+b+',input_string)
    )

def generate_derivation(input_string):
    """Generate the derivation for a valid string."""
    derivation = ["S"]
    state = "S"
    
    for char in input_string:
        if state == "S" and char == 'a':
            derivation.append("S -> aA")
            state = "A"
        elif state == "A" and char == 'a':
            derivation.append("A -> aA")
        elif state == "A" and char == 'b':
            derivation.append("A -> bB")
            state = "B"
        elif state == "B" and char == 'b':
            derivation.append("B -> bB")
    
    derivation.append("B -> ε")
    return derivation


def main():
    print("Grammar: S -> aA | ε, A -> aA | bB, B -> bB | ε")
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
            print("\nInvalid string. The string must start with 'a' and have an equal number of 'a's and 'b's.\n")

if name == "main":
    main()

//9.language anbn,n<0
#PDA on page:
	L={a^nb^n,n>=1}
        M=({q0,q1,qf},{a,b},{a,z},δ,q0,z,{q0})
	δ(q0,a,z)={(q0,az)}
	δ(q0,a,a)={(q0,aa)}
	δ(q0,b,a)={(q1,ε)}
	δ(q0,ε,z)={(qf,ε)}
	δ(q1,b,a)={(q1,ε)}
# Initialize the stack and the state

stack = []
state = "q0"  
#PDA=(Q,Σ,Γ,δ,q0,z0,F)
def reset():
    global stack, state
    stack = []
    state = "q0"

def process_input(input_string):
    global stack, state
    reset()  

    print(f"Initial state: {state}, Stack: {stack}")
    accepted = False  

    for symbol in input_string:
        print(f"Processing symbol: {symbol}")

        if state == "q0":
            if symbol == 'a':
                stack.append('X')  # Push X onto the stack for each 'a'
                print(f"Transition: {state} -> {state} (push X), Stack: {stack}")
            elif symbol == 'b' and stack:
                state = "q1"  # Transition to q1 on first 'b' and pop from stack
                stack.pop()
                print(f"Transition: {state} (pop X), Stack: {stack}")
            else:
                print(f"Rejected at state {state} due to invalid input.")
                return False  # Reject if 'b' appears without matching 'a'

        elif state == "q1":
            if symbol == 'b' and stack:
                stack.pop()  
                print(f"Transition: {state} -> {state} (pop X), Stack: {stack}")
            else:
                print(f"Rejected at state {state} due to invalid input.")
                return False  

    
    if state == "q1" and not stack:
        accepted = True
        print(f"Accepted. Final state: {state}, Stack: {stack}")
    
    return accepted


while True:
    user_input = input("Enter a string of a's and b's (or type 'exit' to quit): ")

    if user_input.lower() == 'exit':
        print("Exiting program.")
        break

    result = "Accepted" if process_input(user_input) else "Rejected"
    if result == "Rejected":
        print(f"Input: {user_input} -> {result}\n")
    else:
        print(f"Input: {user_input} -> {result}\n")

//10.WcWr
#PDA on page:
	L={wcw^r,wε{a,b}*}
        M=({q0,q1,q2,q3},{a,b,c},{a,b,z},δ,q0,z,{q3})
	δ(q0,a,z)={(q0,az)}
	δ(q0,a,a)={(q0,aa)}
	δ(q0,b,z)={(q0,bz)}
	δ(q0,b,a)={(q0,ba)}
	δ(q0,b,b)={(q0,bb)}
	δ(q0,c,a)={(q1,a)}
	δ(q0,c,b)={(q1,b)}
	δ(q1,a,a)={(q1,ε)}
	δ(q1,b,b)={(q1,ε)}
	δ(q1,ε,z)={(q1,ε)}
	δ(q1,ε,ε)={(q1,ε)}
# Initialize the stack and t
def reset():
    global stack, state
    stack = []
    state = "q0"

def process_input(input_string):
    global stack, state
    reset()  

   
    if input_string == 'c':
        print(f"Accepted: Input is just 'c' (w is epsilon).")
        return True

    print(f"Initial state: {state}, Stack: {stack}")
    accepted = False
    seen_c = False  

    for symbol in input_string:
        print(f"Processing symbol: {symbol}")

        if state == "q0":
            if symbol == 'c':
                if seen_c or not stack:
                    print("Rejected: Invalid placement of 'c'.")
                    return False
                state = "q1"
                seen_c = True
                print(f"Transition to {state}, Stack: {stack}")
            else:
                stack.append(symbol)  
                print(f"Pushing {symbol} to stack, Stack: {stack}")
        
        elif state == "q1":
            if not stack or stack.pop() != symbol:  
                print("Rejected: Reverse part does not match.")
                return False
            print(f"Popping {symbol}, Stack: {stack}")

    if state == "q1" and not stack:
        accepted = True
        print(f"Accepted. Final state: {state}, Stack: {stack}")
    else:
        print("Rejected: Stack is not empty after processing.")

    return accepted


while True:
    user_input = input("Enter a string of the form wcwʳ (or type 'exit' to quit): ")

    if user_input.lower() == 'exit':
        print("Exiting program.")
        break

    result = "Accepted" if process_input(user_input) else "Rejected"
    print(f"Input: {user_input} -> {result}\n")