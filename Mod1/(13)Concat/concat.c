#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concat(char **s, int n)
{
    int length = 1;
    for(int i = 0; i <= n - 1; i++) length += strlen(s[i]);
    
    char *final_string = (char*)malloc(length);
    char zero[1] = "";
    strcpy(final_string, zero);
    for(int i = 0; i <= n - 1; i++) strcat(final_string, s[i]);
    
    return final_string;
}

int main(int argc, char **argv)
{
    
    int n;
    scanf("%d", &n);
    
    char *strings[n + 1];
    for(int i = 0; i <= n; i++){
        strings[i] = (char*)malloc(100 * sizeof(char));
        gets(strings[i]);
    }
    
    char *final_string = concat(strings, n + 1);
    printf("%s\n", final_string);
    
    for(int i = 0; i <= n; i++) free(strings[i]);
    free(final_string);
    
    return 0;
}
