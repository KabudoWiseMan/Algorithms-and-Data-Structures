#include <stdlib.h>
#include <stdio.h>


void bubblesort(unsigned long nel,
                int (*compare)(unsigned long i, unsigned long j),
                void (*swap)(unsigned long i, unsigned long j))
{
    unsigned long i, j;
    unsigned long end = nel - 1, start = 0, remember_end = nel - 1, remember_start = 0;
    int how_to_go = 1;
    while (end != start){
        if(how_to_go){
            int swap_or_not = 0;
            for(i = start, j = start + 1; i <= end - 1; i++, j++){
                if(compare(i, j) == 1){
                    swap(i, j);
                    swap_or_not = 1;
                    remember_end = i;
                }
            }
            if(!swap_or_not) break;
            end = remember_end;
            how_to_go = 0;
        }
        else{
            int swap_or_not = 0;
            for(i = end, j = end - 1; i >= start + 1; i--, j--){
                if(compare(i, j) == -1){
                    swap(i , j);
                    swap_or_not = 1;
                    remember_start = i;
                }
            }
            if(!swap_or_not) break;
            start = remember_start;
            how_to_go = 1;
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

void bubblesort(unsigned long,
                int (*)(unsigned long, unsigned long),
                void (*)(unsigned long, unsigned long));

int main(int argc, char **argv)
{
    int i, n;
    scanf("%d", &n);
    
    array = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) scanf("%d", array+i);
    
    bubblesort(n, compare, swap);
    for (i = 0; i < n; i++) printf("%d␣", array[i]);
    printf("\n");
    
    free(array);
    return 0;
}
