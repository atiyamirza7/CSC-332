// Lab 1: Link List Implementation
// Atiya Mirza
// CSC 332
// Question 2

#include <stdio.h>
#include <stdlib.h>

// Create a circular link list item (node)
struct node {
    int data;
    struct node *next;
};

// Makes life easier, didn't do this for question 1
typedef struct node node;
node *head = NULL, *tail = NULL;

// Insert new item at start of list
void insertStart(int data) {
    node *newItem = (node *)malloc(sizeof(node));
    newItem->data = data;
    newItem->next = newItem;

    if (head == NULL) {
        head = newItem;
        tail = newItem;
    } else {
        newItem->next = head;
        tail->next = newItem;
        head = newItem;
    }
}

// Insert new item at end of list
void insertEnd(int data) {
    node *newItem = (node *)malloc(sizeof(node));
    newItem->data = data;
    newItem->next = newItem;

    if (head == NULL) {
        head = newItem;
        tail = newItem;
    } else {
        tail->next = newItem;
        newItem->next = head;
        tail = newItem;
    }
}

// Delete an item from list
void deleteNode(int data) {
    if (head == NULL) return; // for empty list
    // for list with one item
    if (head->data == data && head->next == head) {
        free(head);
        head = NULL;
        return;
    }
    node *temp = head, *d;
    if (head->data == data) { // to delete last item
        while (temp->next != head) temp = temp->next;
        temp->next = head->next;
        free(head);
        head = temp->next;
    }
    
    // search for item to delete
    while (temp->next != head && temp->next->data != data) {
        temp = temp->next;
    }
    // removing the item
    if (temp->next->data == data) {
        d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

// Search for an item in list
int searchNode(int data) {
    node *current = head;
    do {
        if (current == NULL)
        return 0;
        if (current->data == data)
        return 1;
        current = current->next;
    } while (current != head);
    return 0;
}

// Traverse to give count of elements in the list
int countList() {
    if (head == NULL) return 0;
    int count = 0;
    node *current = head;
    do {
        count++;
        current = current->next;
    } while (current != head);
    return count;
}

// Traverse to print list
void printList() {
    if (head == NULL) return;
    node *current = head;
    do {
        printf(" %d ", current->data);
        current = current->next;
    } while(current != head);
}

// Main program
int main() {
    // insert
    insertEnd(1);
    insertStart(3);
    insertStart(5);
    insertEnd(7);
    insertEnd(9);

    // traverse
    printf("\nCircular linked list:");
    printList();
    printf("\nCount of number of elements is: %d", countList());
    printf("\n");

    // delete
    deleteNode(9);
    printf("\nList after deleting an item:");
    printList();
    printf("\n");

    // search
    int findItem = 9;
    printf("Searching...");
    if (searchNode(findItem)) {
        printf("\n%d is found in the linked list", findItem);
        printf("\n");
    } else {
        printf("\n%d is not found in the linked list", findItem);
        printf("\n");
    }
    printf("\nCircular linked list:");
    printList();
    printf("\nCount of number of elements is: %d", countList());
    printf("\n\n");
}

