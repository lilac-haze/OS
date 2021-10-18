
#include <stdlib.h>

struct list {
    void** arr;
    int size;
};

struct list create_list(void* item);
void add(struct list* lst, void* item);
void insert(struct list* lst, int index, void* item);
int size(struct list lst);
void delete_a(struct list* lst, int index);
void set(struct list* lst, int index, void* item);
void* get(struct list* lst, int index);


