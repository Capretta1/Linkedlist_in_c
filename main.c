#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <_ctype.h>


typedef struct Node {
    int data;
    struct Node* node;
} Node;


typedef struct LinkedList {
    Node* head;
    Node* tail; //optional for efficiency
    int size;
}LinkedList;

// function to initialize the linked list
void init_list(LinkedList* list) {
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0; // Initialize size to 0
}

// function to get the size of the linked list
int size(LinkedList* list) {     // ✅ Return type is int
    return list->size;           // ✅ list->size is an int
}

//function to check if the linked list is empty
bool isEmpty(LinkedList* list) {
    return list -> size == 0;
}

// function for adding a new node at the front of the linked list
void push_front(LinkedList* list, int value) {
    Node* new_node  = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node -> data  = value;
    new_node -> node = list -> head; //link new node to current first node
    list -> head = new_node; //new node becomes first node

    if (list -> tail == NULL) {
        list -> tail = new_node; // If the list was empty, set tail to new node
    }
    list -> size++;
}

// function to remove and return the first element of the linked list
int pop_front(LinkedList* list) {
    if (list->head == NULL) { //Check if the list is empty — if yes, you can handle it by returning an error value or exiting.
        fprintf(stderr, "Error: pop_front from empty list\n");
        exit(EXIT_FAILURE);  // or handle differently
    }
    Node* temp = list->head; // Store the current head
    int value  = temp -> data;

    list -> head = temp -> node; //Move head pointer to the next node.
    free(temp); // Free the old head node
    list -> size--; // Decrease the size of the list

    if (list -> head == NULL) {
        list -> tail = NULL; // If the list is now empty, set tail to NULL
    }

    return value; // Return the value of the popped node
}
int main(void) {
    LinkedList list;
    init_list(&list);

    push_front(&list, 10);
    push_front(&list, 20);
    push_front(&list, 30);

    printf("Size after push_front: %d\n", size(&list)); // Should print 3
    printf("Pop front: %d\n", pop_front(&list));  // Should print 30
    printf("Pop front: %d\n", pop_front(&list));  // Should print 20
    printf("Is empty? %s\n", isEmpty(&list) ? "true" : "false");  // Should print false

    // Let's print the list front to back manually to check correctness
    Node* current = list.head;
    printf("List elements: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->node; // Move to the next node
    }
    printf("\n");



    return 0;
}