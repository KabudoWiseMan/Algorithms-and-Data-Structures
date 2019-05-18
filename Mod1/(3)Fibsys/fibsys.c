#include <stdio.h>

int main(int argc, char **argv)
{
    unsigned long long x;
    scanf("%llu", &x);
    
    if(x == 0) printf("0");
    
    unsigned long long previous_number = 1, number = 1, max_fib = 1;
    int length_of_fib = 0, if_there_1 = 1;
    while(max_fib <= x){
        length_of_fib++;
        previous_number = number;
        number = max_fib;
        max_fib = previous_number + number;
    }
    
    unsigned long long fib_numbers_to_x[length_of_fib];
    int i;
    previous_number = 1;
    number = 1;
    max_fib = 1;
    for(i = (length_of_fib - 1); i >= 0; i--){
        fib_numbers_to_x[i] = max_fib;
        previous_number = number;
        number = max_fib;
        max_fib = previous_number + number;
    }
    
    previous_number = 1;
    number = 1;
    max_fib = 1;
    while(x != 0){
        previous_number = 1;
        number = 1;
        max_fib = 1;
        max_fib = previous_number + number;
        while(max_fib <= x){
            previous_number = number;
            number = max_fib;
            max_fib = previous_number + number;
        }
        if(max_fib > x) max_fib = number;
        x -= max_fib;
        for(i = 0; i <= (length_of_fib - 1); i++)
            if(fib_numbers_to_x[i] == max_fib)
                fib_numbers_to_x[i] = 1;
        if(max_fib == 1) if_there_1 = 0;
    }
    
    if(if_there_1 == 1) fib_numbers_to_x[length_of_fib - 1] = 0;
    
    for(i = 0; i <= (length_of_fib - 1); i++)
        if(fib_numbers_to_x[i] != 1) fib_numbers_to_x[i] = 0;
    
    for(i = 0; i <= (length_of_fib - 1); i++) printf("%llu", fib_numbers_to_x[i]);
    
    return 0;
}
