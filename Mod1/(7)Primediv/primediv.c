#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
    signed int x;
    scanf("%d", &x);
    if (x < 0) x = abs(x);
    
    unsigned int sqrt_x = sqrt(x), a[sqrt_x], i, j;
    
    a[0] = 0;
    a[1] = 0;
    for(i = 0; i <= sqrt_x; i++) a[i] = i;
    
    for (i = 2; i <= sqrt_x; i++){
        if(a[i] != 0){
            for (j = (i * i); j <= sqrt_x; j += i) a[j] = 0;
            while((x % i) == 0)x /= i;
        }
    }

    unsigned int max = 0;
    for (i = sqrt_x; i > 0; i--){
        if(a[i] != 0){
            max = a[i];
            break;
        }
    }
    if (x > max) printf("%u\n", x);
    else printf("%u\n", max);
    return 0;
}
