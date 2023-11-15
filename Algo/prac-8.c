

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int S[25] = {0};
int top = -1;
int ch;

void push(int ele) {
    if(top == 24) {
        printf("\n Stack is Full");
    } else {
        top++;
        S[top] = ele;
    }
}

int pop() {
    if(top == -1) {
        printf("\n Stack is Empty");
        return -1;
    } else {
        ch = S[top];
        top--;
        return ch;
    }
}

void display() {
    printf("\n Stack S = ");
    for(int i=0; i<=top; i++) {
        printf("| %d", S[i]);
    }
}

int main() {
    char postfix[25] = {10}, ele;
    int i, num1, num2, ans;
    
    printf("\nEnter postfix Expression: ");
    scanf("%s",postfix);
    printf("\nPostfix Expression: %s", postfix);
    
    i=0;
    while(i < strlen(postfix)) {
        ele = postfix[i];
        if(isdigit(ele)) {
            push(ele - '0');
        } else {
            num1 = pop();
            num2 = pop();
            
            switch(ele) {
                case '^':
                    ans = pow(num2,num1);
                    break;
                case '/':
                    ans = num2/num1;
                    break;
                case '*':
                    ans = num2 * num1;
                    break;
                case '+':
                    ans = num2 + num1;
                    break;
                case '-':
                    ans = num2 - num1;
                    break;
            }
            push(ans);
        }
        display();
        i++;
    }
    
    printf("\nAns = %d",pop());
    return 0;
}

