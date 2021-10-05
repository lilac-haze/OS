#include <stdio.h>
#include "list.h"

void print_int_list(struct list lst)
{
    for (int i = 0; i < lst.size; i++)
        printf("%d ", *((int*)lst.arr[i]));
    printf("\n");
}

int main(void){
int a = 32, b = 12, c = -7, d = -10, t = 100;
    
    struct list lst = create_list(&a);
    
	add(&lst, &b);
    
	printf("Add to end\n");
    add(&lst, &c);
    print_int_list(lst);
    printf("Add to pos [1]\n");
    insert(&lst, 1, &d);
    print_int_list(lst);
    printf("Size\n");
    int s=size(lst);
    printf("%d\n", s);
    printf("ArrayList:\n");
    print_int_list(lst);
    printf("Delete in pos [0]\n");
    delete_a(&lst, 0);
    print_int_list(lst);
    printf("Change in pos [1]\n");
    set(&lst, 1, &t);
    print_int_list(lst);
    printf("Get in pos [0]\n");
    printf("%d\n", *((int*)get(&lst, 0)));
    
    free(lst.arr);
    return EXIT_SUCCESS;
}

