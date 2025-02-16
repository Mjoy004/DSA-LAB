#include <stdio.h>
#include <stdlib.h>

// Structure for a Node
struct Node {
    int data;
    struct Node* next;
};

// Head pointer (global)
struct Node* head = NULL;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    printf("%d inserted at the beginning.\n", value);
}

// Function to insert at the end
void insertAtEnd(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("%d inserted at the end.\n", value);
}

// Function to delete from the beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    printf("%d deleted from the beginning.\n", temp->data);
    free(temp);
}

// Function to delete from the end
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (head->next == NULL) {  // If only one node is present
        printf("%d deleted from the end.\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    printf("%d deleted from the end.\n", temp->data);
    prev->next = NULL;
    free(temp);
}

// Function to search for an element
void search(int key) {
    struct Node* temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            printf("%d found at position %d.\n", key, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("%d not found in the list.\n", key);
}

// Function to display the linked list
void display() {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display();
    
    search(30);
    search(50);

    deleteFromBeginning();
    display();
    
    deleteFromEnd();
    display();

    return 0;
}
