#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int data;
    struct Node* node;
} Node;


typedef struct LinkedList {
    Node* head;
    Node* tail; //optional for efficiency
    int size;
}LinkedList;

void init_list(LinkedList* list) {
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0; // Initialize size to 0
}

int size(LinkedList* list) {     // ✅ Return type is int
    return list->size;           // ✅ list->size is an int
}

int main(void) {
    LinkedList list;
    init_list(&list);

    printf("List initialized.\n");
    printf("Size: %d\n", size(&list));  // Should print 0


    return 0;
}