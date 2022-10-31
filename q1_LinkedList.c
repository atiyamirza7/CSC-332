// Lab 1: Link List Implementation
// Atiya Mirza
// CSC 332
// Question 1

#include <stdio.h>
#include <stdlib.h>

// Create a link list item (node)
struct node {
    int data;
    struct node* next;
};

// Traverse to give count of number of elements in list
int countList(struct node* head) {
    if (head == NULL) return 0; // base case
    int count = 0;
    struct node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

// Traverse to print list
void printList(struct node* node) {
    if (node == NULL) return; // base case
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

// Insert new item at start of list
void insertStart(struct node** head, int data) {
    struct node* newItem;
    newItem = malloc(sizeof(struct node));

    newItem->data = data;
    newItem->next = *head;

    *head = newItem;
}

// Insert new item at end of list
void insertEnd(struct node** head, int data) {
    struct node* newItem;
    newItem = malloc(sizeof(struct node));

    struct node* tail;
    tail = *head;

    newItem->data = data;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
        return;
    } 
    while (tail->next != NULL) tail = tail->next;
    tail->next = newItem;
    return;
}

// Delete an item from list
void deleteNode(struct node** head, int data) {
    struct node *temp = *head, *prev;
    
    // deleting first item scenario
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // search for (non-first) item to delete
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    // if item is not in list
    if (temp == NULL) return;
    // removing the item
    prev->next = temp->next;
    free(temp);
}

// Search for an item in list
int searchNode(struct node** head, int data) {
    struct node* current = *head;

    while (current != NULL) {
        if (current->data == data) 
        return 1;
        current = current->next;
    }
    return 0;
}

// Sort list in ascending order (using bubble sort)
void sortList(struct node** head) {
    struct node *current = *head; 
    struct node *sort = NULL;
    int temp;

    if (head == NULL) {
        return; // for empty list
    } else {
        while (current != NULL) {
            // sort points to item next to current item
            sort = current->next;
            while (sort != NULL) {
                // checking if value of current item is greater than next item
                // if greater, swap current and sort
                if (current->data > sort->data) {
                    temp = current->data;
                    current->data = sort->data;
                    sort->data = temp;
                }
                sort = sort->next;
            
            }
            current = current->next;
        }
    }
}

// Main program
int main() {
    struct node* head = NULL;
    // insert
    insertEnd(&head, 1);
    insertStart(&head, 3);
    insertEnd(&head, 5);
    insertStart(&head, 6);
    insertStart(&head, 7);
    insertEnd(&head, 9);

    // traverse
    printf("\nLinked list:");
    printList(head);
    printf("\nCount of number of elements is: %d", countList(head));
    printf("\n");

    // delete
    deleteNode(&head, 6);
    printf("\nList after deleting an item:");
    printList(head);
    printf("\n");

    // search
    int findItem = 6;
    printf("Searching...");
    if (searchNode(&head, findItem)) {
        printf("\n%d is found in the linked list", findItem);
        printf("\n");
    } else {
        printf("\n%d is not found in the linked list", findItem);
        printf("\n");
    }

    // sort
    sortList(&head);
    printf("\nSorted list:");
    printList(head);
    printf("\nCount of number of elements is: %d", countList(head));
    printf("\n\n");
}
