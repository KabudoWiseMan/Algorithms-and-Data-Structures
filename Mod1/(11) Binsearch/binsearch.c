#include <stdio.h>

unsigned long binsearch(unsigned long nel, int (*compare)(unsigned long i))
{
    unsigned long left = 0, right = nel - 1, med;
    while(left <= right){
        med = (left + right) / 2;
        if(compare(med) == 1) right = med - 1;
        else{
            if(compare(med) == -1) left = med + 1;
            else return med;
        }
    }
    return nel;
}

int array[] = {
    110,
    914,
    915
};

const int k = 337;

int compare(unsigned long i)
{
    if (array[i] == k) return 0;
    if (array[i] < k) return -1;
    return 1;
}

unsigned long binsearch(unsigned long, int (*)(unsigned long));

int main(int argc, char **argv)
{
    printf("%lu\n", binsearch(3, compare));
    return 0;
}
