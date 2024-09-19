#include <stdio.h>

int stack[100];
int Top=0;
int size;
void push(void){
    int element;
    if(Top==size)
    {
        printf("Stack Full\n");
    }
    else 
    {
        printf("Enter element to push:");
        scanf("%d",&element);
        stack[Top]=element;
        Top++;
    }
}
void pop(void)
{
    int element;
    if(Top==0)
    {
        printf("Empty Stack\n");
    }else {
        Top--;
        element=stack[Top];
        printf("Element popped=%d\n",element);
    }
}
void peek(void)
{
    if(Top==0)
    {
        printf("Empty Stack\n");
    }else{
        printf("Top element=%d\n",stack[Top-1]);
    }
}
void displayStack(void)
{
    int i;
    if(Top==0)
    {
        printf("Empty Stack\n");
    } else{
        printf("Stack Elements:\n");
        for(i=Top-1;i>=0;i--){
            printf("%d\n",stack[i]);
        }
        printf("\n");
        
    }
    
}
int main()
{
    int choice;
    printf("Enter the size of stack :");
    scanf("%d",&size);
    while(1){
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Display Stack\n5.Quit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            push();
            break;
            case 2:
            pop();
            break;
            case 3:
            peek();
            break;
            case 4:
            displayStack();
            break;
            case 5:
            printf("Exiting..\n");
            return 0;
            default:
            printf("Invalid choice.try again\n");
        }
    }
    return 0;
}