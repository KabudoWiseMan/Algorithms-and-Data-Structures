#include <stdlib.h>
#include <stdio.h>

void shellsort(unsigned long nel,
               int (*compare)(unsigned long i, unsigned long j),
               void (*swap)(unsigned long i, unsigned long j))
{
    int fib[100], element = 0, next_element = 1, remember_element, quantity = 0;
    while(element + next_element < nel){
        remember_element = next_element;
        next_element += element;
        element = remember_element;
        fib[quantity] = next_element;
        quantity++;
    }
    
    for(int i = quantity - 1; i >= 0; i--){
        for(int j = fib[i]; j <= nel - 1; j++){
            if(compare(j , j - fib[i]) == -1){
                swap(j , j - fib[i]);
                for(int k = j - fib[i]; k - fib[i] >= 0; k -= fib[i]){
                    if(compare(k, k - fib[i]) == -1){
                        swap(k, k - fib[i]);
                    }
                    else break;
                }
            }
        }
    }
}


int *array;

int compare(unsigned long i, unsigned long j)
{
    if (i <= j) {
        printf("COMPARE␣%d␣%d\n", i, j);
    } else {
        printf("COMPARE␣%d␣%d\n", j, i);
    }
    
    if (array[i] == array[j]) return 0;
    return array[i] < array[j] ? -1 : 1;
}

void swap(unsigned long i, unsigned long j)
{
    if (i <= j) {
        printf("SWAP␣%d␣%d\n", i, j);
    } else {
        printf("SWAP␣%d␣%d\n", j, i);
    }
    
    int t = array[i];
    array[i] = array[j];
    array[j] = t;
}

void shellsort(unsigned long,
               int (*)(unsigned long, unsigned long),
               void (*)(unsigned long, unsigned long));

int main(int argc, char **argv)
{
    int i, n;
    scanf("%d", &n);
    
    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", array+i);
    
    shellsort(n, compare, swap);
    for (i = 0; i < n; i++) printf("%d␣", array[i]);
    printf("\n");
    
    free(array);
    return 0;
}
