#include <stdio.h>
#include <math.h>

int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%d", &n);
    
    double a, b, fraction, maxsum, sum = 0;
    unsigned int l = 0, r = 0, start = 0, i = 0;
    while(i <= n - 1){
        scanf("%lf/%lf", &a, &b);
        fraction = log2(a / b);
        if(i == 0) maxsum = fraction;
        sum += fraction;
        if(sum > maxsum){
            maxsum = sum;
            l = start;
            r = i;
        }
        i++;
        if(sum < 0){
            sum = 0;
            start = i;
        }
    }
    
    printf("%d %d\n", l, r);
    
    return 0;
}
