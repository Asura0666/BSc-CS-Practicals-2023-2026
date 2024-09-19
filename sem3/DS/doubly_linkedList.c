
#include <stdio.h>
#include <stdlib.h>

struct S {
	int data;
	struct S* next;
	struct S* prev;
};

struct S* head = NULL;

void displayForward();
void displayBackward();
void search();
void insertAtBeginning();
void insertAtEnd();
void insertAtPosition();
void deleteAtBeginning();
void deleteAtEnd();
void deleteAtPosition();
void deleteValue();
int getSize();

void displayForward() {
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	struct S* temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}

void displayBackward() {
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	struct S* temp;
	temp = head;
	while(temp->next!=NULL)
		temp = temp->next;
	while(temp!=NULL) {
		printf("%d\n", temp->data);
		temp = temp->prev;
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
	struct S* temp = head;
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
	struct S* temp = (struct S*)malloc(sizeof(struct S));
	if (temp == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	temp->data = x;
	temp->next = head;
	if (head != NULL) {
		head->prev = temp;
	}
	head = temp;
}

void insertAtEnd() {
	int x;
	printf("Enter the number to insert at end: ");
	if (scanf("%d", &x) != 1) {
		printf("Invalid input\n");
		while (getchar() != '\n');
		return;
	}
	struct S* temp = (struct S*)malloc(sizeof(struct S));
	if (temp == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	temp->data = x;
	temp->next = NULL;
	if (head == NULL) {
		head = temp;
	} else {
		struct S* t = head;
		while (t->next != NULL) {
			t = t->next;
		}
		t->next = temp;
		temp->prev = t;
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
	struct S* temp = (struct S*)malloc(sizeof(struct S));
	if (temp == NULL) {
		printf("Memory allocation failed\n");
		return;
	}
	temp->data = x;
	if (pos == 1) {
		temp->next = head;
		if (head != NULL) {
			head->prev =temp;
		}
		head = temp;
	} else {
		struct S* t = head;
		for (int i = 1; i < pos - 1; i++) {
			t = t->next;
		}
		temp->next = t->next;
		if (t->next != NULL) {
			t->next->prev = temp;
		}
		t->next = temp;
		temp->prev = t;
	}
}

void deleteAtBeginning() {
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	struct S* temp = head;
	if (temp->next != NULL) {
		temp->next->prev = NULL;
	}

	head = temp->next;
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
	struct S* temp = head;
	while (temp->next!= NULL) {
		temp = temp->next;
	}
	free(temp);
	temp->prev->next = NULL;
}

void deleteAtPosition() {
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	int pos;
	printf("Enter the position to delete (1-%d): ", getSize());
	scanf("%d", &pos);
	if (pos < 1 || pos > getSize()) {
		printf("Invalid position\n");
		return;
	}
	if (pos == 1) {
		struct S* temp = head;
		head = temp->next;
		if (head != NULL) {
			head->prev = NULL;
		}
		free(temp);
	} else {
		struct S* t = head;
		for (int i = 1; i < pos - 1; i++) {
			t = t->next;
		}
		struct S* temp = t->next;
		t->next = temp->next;
		if (temp->next != NULL) {
			temp->next->prev = t;
		}
		free(temp);
	}
}

void deleteValue() {
	if (head == NULL) {
		printf("Linked List is empty\n");
		return;
	}
	int x;
	printf("Enter the Value to Delete: ");
	scanf("%d",&x);

	struct S* temp = head;
	int found = 0;
	while (temp!= NULL) {
		if(temp->data == x) {
			if (temp->prev!= NULL) {
				temp->prev->next = temp->next;
			} else {
				head = temp->next;
			}
			if (temp->next!= NULL) {
				temp->next->prev = temp->prev;
			}
			struct S* next = temp->next;
			free(temp);
			temp = next;
			found = 1;
		} else {
			temp = temp->next;
		}
	}
	if (!found) {
		printf("Invalid value\n");
	}
}

int getSize() {
	int size = 0;
	struct S* temp = head;
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
		printf("7. Delete Value\n");
		printf("8. Search\n");
		printf("9. Display Forward\n");
		printf("10. Display Backward\n");
		printf("11. Quit\n");
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
			deleteValue();
			break;
		case 8:
			search();
			break;
		case 9:
			displayForward();
			break;
		case 10:
			displayBackward();
			break;
		case 11:
			printf("Exiting...\n");
			exit(0);
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}