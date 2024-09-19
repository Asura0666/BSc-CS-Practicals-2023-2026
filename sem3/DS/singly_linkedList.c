#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void display();
void search();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition();
int getSize(); 

void display() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void search() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    int x;
    printf("Enter the number to search: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == x) {
            printf("Element %d found\n", x);
            return;
        }
        temp = temp->next;
    }
    printf("Element %d not found\n", x);
}

void insertAtBeginning() {
    int x;
    printf("Enter the number to insert at beginning: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd() {
    int x;
    printf("Enter the number to insert at end: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtPosition() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    int pos, x;
    printf("Enter the position to insert (1-%d): ", getSize() + 1);
    if (scanf("%d", &pos) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    if (pos < 1 || pos > getSize() + 1) {
        printf("Invalid position\n");
        return;
    }
    printf("Enter the number to insert: ");
    if (scanf("%d", &x) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = x;
    if (pos == 1) {
        newNode->next = head;
        head = newNode;
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginning() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
}

void deleteAtEnd() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtPosition() {
    if (head == NULL) {
        printf("Linked List is empty\n");
        return;
    }
    int pos;
    printf("Enter the position to delete (1-%d): ", getSize());
    if (scanf("%d", &pos) != 1) {
        printf("Invalid input\n");
        while (getchar() != '\n');  
        return;
    }
    if (pos < 1 || pos > getSize()) {
        printf("Invalid position\n");
        return;
    }
    if (pos == 1) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    } else {
        struct Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }
        struct Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        free(nodeToDelete);
    }
}

int getSize() {
    int size = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        size++;
        temp = temp->next;
    }
    return size;
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert Beginning\n");
        printf("2. Insert End\n");
        printf("3. Insert Position\n");
        printf("4. Delete Beginning\n");
        printf("5. Delete End\n");
        printf("6. Delete Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Quit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');  
            continue;
        }
        switch (choice) {
            
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                insertAtPosition();
                break;
            case 4:
                deleteAtBeginning();
                break;
            case 5:
                deleteAtEnd();
                break;
            case 6:
                deleteAtPosition();
                break;
            case 7:
                search();
                break;
            case 8:
                display();
                break;
            case 9:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
                break;
        }
    }
    return 0;
}