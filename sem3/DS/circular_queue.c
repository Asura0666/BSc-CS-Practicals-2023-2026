#include <stdio.h>

int queue[100];
int front = -1;
int rear = -1;
int size;

void insert(void) {
    int element;
    if ((rear + 1) % size == front) {
        printf("Queue Full\n");
    } else {
        printf("Enter element to insert: ");
        scanf("%d", &element);
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % size;
        queue[rear] = element;
        printf("Element inserted: %d\n", element);
    }
}

void delete(void) {
    int element;
    if (front == -1) {
        printf("Empty Queue\n");
    } else {
        element = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % size;
        }
        printf("Element deleted: %d\n", element);
    }
}

void displayQueue(void) {
    int i;
    if (front == -1) {
        printf("Empty Queue\n");
    } else {
        printf("Queue Elements: ");
        for (i = front; i != rear; i = (i + 1) % size) {
            printf("%d ", queue[i]);
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice;
    printf("Enter the size of queue: ");
    scanf("%d", &size);

    if (size > 100) {
        printf("Size exceeds the maximum allowed.\n");
        return 1;
    }

    while (1) {
        printf("\n1.Insert\n2.Delete\n3.Display Queue\n4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                printf("Exiting..\n");
                return 0;
            default:
                printf("Invalid choice. Try again\n");
        }
    }
    return 0;
}