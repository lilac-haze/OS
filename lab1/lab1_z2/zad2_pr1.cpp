#include <stdio.h>
#include <stdlib.h>
#include <time.h>       
 
int main ()
{
	 printf("**********Zadanie 1**********\n\n");
    srand(time(NULL));
    int n, i;
    int sum = 0, count = 0;
    int sum1;
    printf("Vvedite kol-vo elementov massiva: ");
    scanf("%d", &n);
    int arr[n];
    printf("Massiv:");
    for (i = 0; i < n; ++i) {

        //printf("%d elem=: ", i);
        //scanf("&d", &arr[1]);
        
        arr[i] = rand() % 12 - 10;
        printf("%d ", arr[i]);
        sum += arr[i];
    }
    int av = sum / n;
    printf("\nElements of massive that bigger than average: ");
    for (i = 0; i < n; ++i) {

        if (arr[i] > av) {
            ++count;
            printf("%d ", arr[i]);
        }
    }

    printf("\nTotal: %d\n", count);
    
    printf("\n**********Zadanie 2**********\n\n");
    
	printf("Massiv:");
	for (i = 0; i < n; ++i) {

        printf("%d ", arr[i]);
        
    }
    printf("\n");
    char neig;
    neig = -1;
    for (i = 0; i < n; i++) {
        if (arr[i] < 0) {
            neig = i;
            break;
        }
    }
    if (neig == -1) {
        printf("nope");
    }
    else {
        printf("Pervoe negativnoe chislo eto %d element\n", neig + 1);
    }
    sum1 = 0;
    for (i = neig + 1; i < n; i++) {
        sum1 += abs(arr[i]);
    }
    printf("Summa modulei: %d\n", sum1);
    return 0;
}

