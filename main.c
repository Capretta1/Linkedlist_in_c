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
int main(void) {
    LinkedList list;
    init_list(&list);

    printf("List initialized.\n");
    printf("Size: %d\n", size(&list));  // Should print 0
    printf("Is empty? %s\n", isEmpty(&list) ? "true" : "false"); // Should print "true"



    return 0;
}