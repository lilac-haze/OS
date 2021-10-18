#include <stdlib.h>
#include <limits.h>

typedef struct LinkedListNode Node;

typedef struct LinkedListNode {
    int item;
    Node* next;
} Node;

typedef struct {
    int size;
    Node* root;
} LinkedList;


void add(LinkedList* list, int item);
int size(LinkedList* list);
void insert(LinkedList* list, int index, int item);
void delete_a(LinkedList* list, int index);
void set(LinkedList* list, int index, int item);
int get(LinkedList* list, int index);



LinkedList* create_list();
