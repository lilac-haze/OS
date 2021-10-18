#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "list.h"

void print_int_list(LinkedList* list)
{
    int index;
    for (index = 0; index < list->size; index++) {
        printf("%d ", get(list, index));
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
int a = 32, b = 12, c = -7, d = -10, t = 100;
    LinkedList* lst = create_list();

    
    add(lst, a);
    add(lst, b);
    add(lst, c);
    add(lst, d);
    print_int_list(lst);
    printf("\nAdd to end\n");
    add(lst, t);
    
    print_int_list(lst);
    
    
    printf("Add to pos [1]\n");
    insert(lst, 1, 14);
    print_int_list(lst);
    printf("Size\n");
    int s=size(lst);
    printf("%d\n", s);
    printf("ArrayList:\n");
    print_int_list(lst);
    printf("Delete in pos [0]\n");
    delete_a(lst, 0);
    print_int_list(lst);
    printf("Change in pos [1]\n");
    set(lst, 1, 200);
    print_int_list(lst);
    printf("Get in pos [0]\n");
    printf("%d\n", get(lst, 0));

    return EXIT_SUCCESS;
}

