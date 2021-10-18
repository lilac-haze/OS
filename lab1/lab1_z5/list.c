#include <stdlib.h>

#include "list.h"


LinkedList* create_list()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->size = 0;
    list->root = NULL;

    return list;
}


Node* getItem(LinkedList* list, int index)
{
    int i;
    Node* temp = list->root;
    for (i = 0; i <= index; i++) {
        if (i == index) {
            break;
        }
        else {
            temp = temp->next;
        }
    }

    return temp;
}



int isNodeExist(LinkedList* list, int index)
{
    return list->root != NULL && index >= 0 && index < list->size;
}


void add(LinkedList* list, int item)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (list->root == NULL) {
        list->root = newNode;
    }
    else {
    	int index=list->size - 1;
        Node* lastNode = getItem(list, index);
        lastNode->next = newNode;
    }

    list->size++;
}

void insert(LinkedList* list, int index, int item)
{
    if (!isNodeExist(list, index)) {
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->item = item;
    newNode->next = NULL;

    if (index == 0) {
        newNode->next = list->root;
        list->root = newNode;
    }
    else {
        Node* parentOfNodeForInsert = getItem(list, index - 1);
        newNode->next = parentOfNodeForInsert->next;
        parentOfNodeForInsert->next = newNode;
    }

    list->size++;
}

int size(LinkedList* list)
{
    return list->size;
}

void delete_a(LinkedList* list, int index)
{
    if (!isNodeExist(list, index)) {
        return;
    }

    Node* nodeForRemove;
    if (index == 0) {
        nodeForRemove = list->root;
        list->root = list->root->next;
    }
    else {
        Node* parentOfNodeForRemove = getItem(list, index - 1);
        nodeForRemove = parentOfNodeForRemove->next;
        parentOfNodeForRemove->next = nodeForRemove->next;
    }

    free(nodeForRemove);
    list->size--;
}

void set(LinkedList* list, int index, int item)
{
    if (!isNodeExist(list, index)) {
        return;
    }

    Node* node = getItem(list, index);
    node->item = item;
}

int get(LinkedList* list, int index)
{
    if (!isNodeExist(list, index)) {
        return INT_MAX;
    }

    return getItem(list, index)->item;
}



