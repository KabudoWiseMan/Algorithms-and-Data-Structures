#include <stdio.h>

int power_of_2(signed int x){
    int yes_not;
    if(x <= 0) return yes_not = 0;
    if(x == 1) return yes_not = 1;
    while(x % 2 == 0){
        x /= 2;
        if(x == 1) return yes_not = 1;
    }
    return yes_not = 0;
}

int power(int x, int y){
    int x_in_y = 1;
    if(y)
        for(int i = 1; i <= y; i++)
            x_in_y *= x;
    return x_in_y;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    signed int numbers[n];
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    int counter = 0;
    signed int sum = 0;
    for(int i = 1; i <= power(2, n) - 1; i++){
        sum = 0;
        for(int j = 0; j <= n - 1; j++){
            if((i >> j) & 1) sum += numbers[j];
        }
        if(power_of_2(sum)) counter++;
    }
    printf("%d\n", counter);
    return 0;
}
