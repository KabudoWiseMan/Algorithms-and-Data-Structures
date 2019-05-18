#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *fibstr(int n)
{
    char *str = (char*)malloc(1000 * sizeof(char));
    char *next_str = (char*)malloc(1000 * sizeof(char));
    char* helper_str = (char*)malloc(1000 * sizeof(char));
    
    strcpy(str, "a");
    strcpy(next_str, "b");
    
    if(n == 1){
        free(next_str);
        free(helper_str);
        return str;
    }
    
    for(int i = 0; i <= n - 3; i++){
        strcat(str, next_str);
        strcpy(helper_str, str);
        strcpy(str, next_str);
        strcpy(next_str, helper_str);
    }
    
    free(str);
    free(helper_str);
    return next_str;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    char *final_str = fibstr(n);
    printf("%s\n", final_str);
    
    free(final_str);
    
    return 0;
}
