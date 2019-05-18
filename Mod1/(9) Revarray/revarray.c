#include <stdio.h>

void revarray(void *base, unsigned long nel, unsigned long width)
{
    char *arr = (char*)base;
    int element, bit;
    char remember_bit;
    for (element = 0; element <= (nel / 2 - 1) * width; element += width)
        for (bit = 0; bit <= width - 1; bit++)
        {
            remember_bit = *(arr + element + bit);
            *(arr + element + bit) = *(arr + width * (nel - 1) - element + bit);
            *(arr + width * (nel - 1) - element + bit) = remember_bit;
        }
}

int  array[] = {
    1,
    2,
    3,
    4,
    5,
    6
};

void revarray(void*, unsigned long, unsigned long);

int main(int argc, char **argv)
{
    revarray(array, 6, sizeof(int));
    
    int i;
    for (i = 0; i < 6; i++) {
        printf("%d\n", array[i]);
    }
    
    return 0;
}
