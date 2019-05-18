#include <stdio.h>

unsigned long peak(unsigned long nel,
                   int (*less)(unsigned long i, unsigned long j))
{
    unsigned long peak;
    unsigned long start = 0, end = nel - 1, middle;
    while(start < end){
        middle = (start / 2 + end / 2);
        if( less(middle - 1, middle) && less(middle + 1, middle) ){
            peak = middle;
            return peak;
        }else{
            if(less(middle, middle + 1)){
                start = middle + 1;
            }else{
                if(less(middle, middle - 1)){
                    end = middle - 1;
                }
            }
        }
    }
    return start;
}

#include <stdio.h>

int array[] = {
    210,
    462,
    175,
    169
};

int less(unsigned long i, unsigned long j)
{
    return array[i] < array[j];
}

unsigned long peak(unsigned long, int (*)(unsigned long, unsigned long));

int main(int argc, char **argv)
{
    int i = peak(4, less);
    if ((i == 0 || array[i] >= array[i-1]) &&
        (i == 3 || array[i] >= array[i+1])) {
        printf("CORRECT\n");
    } else {
        /* Если функция peak работает правильно,
         сюда никогда не будет передано
         управление! */
        printf("WRONG\n");
    }
    return 0;
}
