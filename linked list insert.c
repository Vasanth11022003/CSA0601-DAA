  #include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    return newNode;
}

void insertInMiddle(struct Node* prevNode, int data) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL for inserting in the middle.\n");
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data;
    int i;

    do {
        printf("\nTesting Conditions:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert in the middle\n");
        printf("3. Insert at the last\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                printf("List after insertion: ");
                printList(head);
                break;

            case 2:
                printf("Enter the number to insert: ");
                scanf("%d", &data);
                printf("Enter the position after which to insert: ");
                int position;
                scanf("%d", &position);
                struct Node* temp = head;
                for (i = 1; i < position && temp != NULL; i++) {
                    temp = temp->next;
                }
                insertInMiddle(temp, data);
                printf("List after insertion: ");
                printList(head);
                break;

            case 3:
                printf("Enter the number to insert: ");
                scanf("%d", &data);
                insertAtEnd(head, data);
                printf("List after insertion: ");
                printList(head);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    return 0;
}

