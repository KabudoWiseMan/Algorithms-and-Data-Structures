#include <stdio.h>

int main(int argc, char **argv)
{
    int a[8], b[8], i;
    for (i = 0; i <= 7; i++) scanf("%d", &a[i]);
    for (i = 0; i <= 7; i++) scanf("%d", &b[i]);
    
    int sum_a = 0, sum_b = 0, multi_a = 1, multi_b = 1;
    for (i = 0; i <= 7; i++){
        sum_a += a[i];
        sum_b += b[i];
        multi_a = multi_a * a[i];
        multi_b = multi_b * b[i];
    }
    if ((sum_a == sum_b)&&(multi_a == multi_b))
        printf("yes\n");
    else
        printf("no\n");
            
    return 0;
}
