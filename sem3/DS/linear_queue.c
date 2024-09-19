#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void insert(int element, int size) {
    if (rear == size - 1) {
        printf("Queue Full\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = element;
        printf("Element inserted: %d\n", element);
    }
}

void delete(int size) {
    if (front == -1 || front > rear) {
        printf("Empty Queue\n");
    } else {
        printf("Element deleted: %d\n", queue[front]);
        front++;
    }
}

void displayQueue(int size) {
    if (front == -1 || front > rear) {
        printf("Empty Queue\n");
    } else {
        printf("Queue Elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int size;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    int choice, element;
    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display Queue\n4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (rear == size - 1) {
                    printf("Queue Full\n");
                } else {
                    printf("Enter element to insert: ");
                    scanf("%d", &element);
                    insert(element, size);
                }
                break;
            case 2:
                delete(size);
                break;
            case 3:
                displayQueue(size);
                break;
            case 4:
                printf("Exiting..\n");
                exit(0);
            default:
                printf("Invalid choice. Try again\n");
        }
    }

    return 0;
}