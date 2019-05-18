#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int wcount(char *s)
{
    int counter = 0, length = strlen(s), i = 0;
    while(i <= length - 1){
        while( ( i <= length - 1) && (s[i] == 32) ) i++;
        if(i > length - 1) break;
        counter++;
        while( (i <= length - 1) && (s[i] != 32) ) i++;
        if(i > length - 1) break;
    }
    return counter;
}

int main(int argc, char **argv)
{
    char *string = (char*)malloc(1000000 * sizeof(char));
    gets(string);
    
    int *how_many_words = wcount(string);
    printf("%d\n", how_many_words);
    
    free(string);
    
    return 0;
}
