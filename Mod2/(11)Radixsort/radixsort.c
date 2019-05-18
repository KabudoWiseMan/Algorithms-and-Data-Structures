#include <stdio.h>
#include <stdlib.h>

union Int32 {
    int x;
    unsigned char bytes[4];
};

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    union Int32 *numbers = (union Int32*)malloc(n * sizeof(union Int32));
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i].x);
    
    for(int j = 0; j <= 4 - 1; j++){
        int keys[256] = { 0 };
        for(int i = 0; i <= n - 1; i++) keys[numbers[i].bytes[j]]++;
        
        int indices[256], index = 0;
        for(int i = 0; i <= 255; i++){ indices[i] = keys[i] + index; index += keys[i]; }
        
        union Int32 *helper = (union Int32*)malloc(n * sizeof(union Int32));
        for(int i = n - 1; i >= 0; i--) helper[--indices[numbers[i].bytes[j]]] = numbers[i];
        for(int i = 0; i <= n - 1; i++) numbers[i] = helper[i];
        
        free(helper);
    }
    
    int i = 0;
    while(i != n){
        if(numbers[i].x < 0) break;
        i++;
    }
    
    union Int32 *helper = (union Int32*)malloc((n - i) * sizeof(union Int32));
    int j, k;
    for(j = i, k = 0; j <= n - 1; j++, k++) helper[k] = numbers[j];
    for(j = n - 1, k = i - 1; k >= 0; j--, k--) numbers[j] = numbers[k];
    for(j = 0; j <= n - i - 1; j++) numbers[j] = helper[j];
    
    free(helper);
    
    for(int t = 0; t <= n - 1; t++) printf("%d ", numbers[t].x);
    
    free(numbers);
    
    return 0;
}
