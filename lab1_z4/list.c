#include <stdlib.h>

#include "list.h"

struct list create_list(void* item)
{
    struct list lst = { (void**)malloc(sizeof(void*)), 1 };
    lst.arr[0] = item;
    return lst;
}

void add(struct list* lst, void* item)
{
    (*lst).size++;
    (*lst).arr = (void**)realloc((*lst).arr, (*lst).size * sizeof(void*));
    (*lst).arr[(*lst).size - 1] = item;
}

void insert(struct list* lst, int index, void* item)
{
    if (index >= 0 && index < (*lst).size) {
        (*lst).size++;
        (*lst).arr = (void**)realloc((*lst).arr, (*lst).size * sizeof(void*));
        for (int i = (*lst).size - 1; i > index; i--) {
            (*lst).arr[i] = (*lst).arr[i - 1];
        }
        (*lst).arr[index] = item;
    }
}

int size(struct list lst)
{
    return lst.size;
}

void delete_a(struct list* lst, int index)
{
    if (index >= 0 && index < (*lst).size) {
        for (int i = index; i < (*lst).size - 1; i++)
            (*lst).arr[i] = (*lst).arr[i + 1];
        (*lst).size--;
        (*lst).arr = (void**)realloc((*lst).arr, (*lst).size * sizeof(void*));
    }
}

void set(struct list* lst, int index, void* item)
{
    if (index >= 0 && index < (*lst).size)
        (*lst).arr[index] = item;
}

void* get(struct list* lst, int index)
{
    if (index >= 0 && index < (*lst).size)
        return (*lst).arr[index];
}
