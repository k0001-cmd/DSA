#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *previous;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
    newNode->previous = NULL;
    return newNode;
}

void insertEnd(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
    newNode->previous = current;
}

void display(struct Node *head) {
    struct Node *current = head;

    printf("List: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void insertBeginning(struct Node **head, int value) {
    struct Node *newNode = createNode(value);

    newNode->next = *head;

    if (*head != NULL) {
        (*head)->previous = newNode;
    }

    *head = newNode;
}

void insertAtPosition(struct Node **head, int value, int position) {
    if (position <= 1 || *head == NULL) {
        insertBeginning(head, value);
        return;
    }

    struct Node *current = *head;
    int place = 1;

    while (place < position - 1 && current->next != NULL) {
        current = current->next;
        place++;
    }

    struct Node *newNode = createNode(value);
    newNode->next = current->next;
    newNode->previous = current;

    if (current->next != NULL) {
        current->next->previous = newNode;
    }

    current->next = newNode;
}

void deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *oldNode = *head;
    *head = (*head)->next;

    if (*head != NULL) {
        (*head)->previous = NULL;
    }

    free(oldNode);
}

void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *current = *head;

    if (current->next == NULL) {
        free(current);
        *head = NULL;
        return;
    }

    while (current->next != NULL) {
        current = current->next;
    }

    current->previous->next = NULL;
    free(current);
}

void deleteAtPosition(struct Node **head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position <= 1) {
        deleteBeginning(head);
        return;
    }

    struct Node *current = *head;
    int place = 1;

    while (place < position && current != NULL) {
        current = current->next;
        place++;
    }

    if (current == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    current->previous->next = current->next;

    if (current->next != NULL) {
        current->next->previous = current->previous;
    }

    free(current);
}

int search(struct Node *head, int value) {
    int position = 1;

    while (head != NULL) {
        if (head->data == value) {
            return position;
        }
        head = head->next;
        position++;
    }

    return -1;
}

int main(void) {
    struct Node *head = NULL;

   
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    insertEnd(&head, 30);
    display(head);

    insertBeginning(&head, 5);
    display(head);

    insertAtPosition(&head, 15, 3);
    display(head);

    deleteBeginning(&head);
    display(head);

    deleteEnd(&head);
    display(head);

    deleteAtPosition(&head, 2);
    display(head);

    int foundAt = search(head, 20);
    if (foundAt != -1) {
        printf("20 found at position %d.\n", foundAt);
    } else {
        printf("20 was not found.\n");
    }

    while (head != NULL) {
        deleteBeginning(&head);
    }

    return 0;
}
