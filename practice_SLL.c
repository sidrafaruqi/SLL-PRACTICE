#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        return NULL;  // Return NULL in case of a memory allocation error
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* insertAtBeginning(struct Node** head, int a) {
    struct Node* x = createNode(a);
    if (*head == NULL) {
        x->next = NULL;
    } else {
        x->next = *head;
    }
    *head = x;
    return *head;
}

struct Node* insertAtEnd(struct Node** head, int data) {
    struct Node* x = createNode(data);
    if (*head == NULL) {
        return x;
    } else {
        struct Node* search = *head;
        while (search->next != NULL) {
            search = search->next;
        }
        search->next = x;
        x->next = NULL;
        return *head;
    }
}

struct Node* insertAfter(struct Node** head, int data, int searchValue) {
    struct Node* x = createNode(data);
    struct Node* search = *head;
    while (search != NULL && search->data != searchValue) {
        search = search->next;
    }
    if (search == NULL) {
        printf("Node with search value not found\n");
        free(x);  // Free the allocated node
        return *head;
    }
    x->next = search->next;
    search->next = x;
    return *head;
}

struct Node* deleteNode(struct Node** head, int data) {
    struct Node* search = *head;
    struct Node* prev = NULL;
    while (search != NULL && search->data != data) {
        prev = search;
        search = search->next;
    }
    if (search == NULL) {
        printf("Node with value not found\n");
        return *head;
    }
    if (prev == NULL) {
        *head = search->next;
    } else {
        prev->next = search->next;
    }
    free(search);
    return *head;
}

struct Node* searchNode(struct Node* head, int data) {
    struct Node* search = head;
    while (search != NULL) {
        if (search->data == data) {
            return search;
        }
        search = search->next;
    }
    return NULL;  // Node not found
}

void printList(struct Node* head) {
    struct Node* search = head;
    while (search != NULL) {
        printf("%d\n", search->data);
        search = search->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Test cases
    head = insertAtBeginning(&head, 10);
    head = insertAtEnd(&head, 20);
    head = insertAfter(&head, 15, 10);

    printf("Original List:\n");
    printList(head);

    struct Node* nodeToDelete = searchNode(head, 15);
    if (nodeToDelete != NULL) {
        head = deleteNode(&head, nodeToDelete->data);
        printf("List after deleting node with value 15:\n");
        printList(head);
    }

    return 0;
}
