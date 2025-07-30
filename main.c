#include <stdio.h>


typedef struct Node {
    int data;
    struct Node* node;
} Node;


typedef struct LinkedList {
    Node* head;
    Node* tail; //optional for efficiency
    Node* size;
}LinkedList;

void inti_list(LinkedList* list) {
    list -> head = NULL;
    list -> tail = NULL;
    list -> size = 0; // Initialize size to 0
}
int main(void) {
    LinkedList list;
    inti_list(&list);
    printf("Size: %d\n",list.size);  // Should print 0


    return 0;
}