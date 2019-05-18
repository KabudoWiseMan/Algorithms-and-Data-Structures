#include <stdio.h>

int main(int argc, char **argv)
{
    int length;
    scanf("%d", &length);
    
    int array[length], i;
    for (i = 0; i <= (length - 1); i++) scanf("%d", &array[i]);
    
    int k;
    scanf("%d", &k);
    
    int max_sum = 0, sum = 0;
    
    for(i = 0; i <= (k - 1); i++){
        sum = sum + array[i];
        max_sum = sum;
    }
    for(i = k; i <= (length - 1); i++){
        sum = sum + array[i] - array[i - k];
        if(max_sum < sum) max_sum = sum;
    }
    printf("%d", max_sum);
    return 0;
}
