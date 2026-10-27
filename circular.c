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
        newNode->next = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != *head) {
        current = current->next;
    }

    current->next = newNode;
    newNode->next = *head;
}

