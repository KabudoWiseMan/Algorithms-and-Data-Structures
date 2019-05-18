#include <stdio.h>

int maxarray(void *base, unsigned long nel, unsigned long width,
             int (*compare)(void *a, void *b))
{
    int id_max_element = 0, i;
    void *max_element = base, *possible_max_element = base + width;
    for(i = 1; i <= nel - 2; i++)
        if(compare(max_element, possible_max_element) < 0){
            max_element = possible_max_element;
            possible_max_element += width;
            id_max_element = i;
        }else{
            possible_max_element += width;
        }
    
    return id_max_element;
}

int array[] = {
    1,
    4,
    3,
    5,
    2
};

int compare(void *a, void *b)
{
    int va = *(int*)a;
    int vb = *(int*)b;
    if (va == vb) return 0;
    return va < vb ? -1 : 1;
}

int maxarray(void*, unsigned long, unsigned long,
             int (*)(void *a, void *b));

int main(int argc, char **argv)
{
    printf("%d\n", maxarray(array, 5, sizeof(int), compare));
    return 0;
}
