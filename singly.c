#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int value) {
    struct Node *newNode = malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    newNode->data = value;
    newNode->next = NULL;
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
    current->next = newNode;
}

void deleteBeginning(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *oldNode = *head;
    *head = (*head)->next;
    free(oldNode);
}

void deleteEnd(struct Node **head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    struct Node *current = *head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    free(current->next);
    current->next = NULL;
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

    while (place < position - 1 && current->next != NULL) {
        current = current->next;
        place++;
    }

    if (current->next == NULL) {
        printf("Position does not exist.\n");
        return;
    }

    struct Node *oldNode = current->next;
    current->next = oldNode->next;
    free(oldNode);
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

    /* Create a list with three nodes: 10, 20, 30 */
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
