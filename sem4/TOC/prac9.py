# Implement a PDA for  language anbn ,  n> 0


class Stack:
    def __init__(self):
        self.stack = []

    def push(self, element):
        self.stack.append(element)
        print(f"Pushed '{element}' into the stack.")

    def pop(self):
        if self.stack:
            popped_element = self.stack.pop()
            print(f"Popped '{popped_element}' from the stack.")
            return popped_element
        else:
            print("Stack is empty! Cannot pop.")
            return None

    def reset_stack(self):
        self.stack = []


def process_input(input_str, stack):
    stack.reset_stack()

    i = 0

    if input_str and input_str[0] == "b":
        print("Input string is invalid: 'b' appears before 'a'.")
        return False

    while i < len(input_str) and input_str[i] == "a":
        stack.push("a")
        i += 1

    while i < len(input_str) and input_str[i] == "b":
        if stack.pop() is None:
            print("Input string is invalid: More 'b's than 'a's.")
            return False
        i += 1

    if i == len(input_str) and not stack.stack:
        return True
    else:
        print("Input string is invalid: Extra 'a's or 'b's.")
        return False


stack = Stack()
while True:
    input_str = input("\nEnter a string or type 'exit' to quit: ").strip()

    if input_str.lower() == "exit":
        print("Exiting...")
        break

    if process_input(input_str, stack):
        print("Accepted")
    else:
        print("Rejected")
