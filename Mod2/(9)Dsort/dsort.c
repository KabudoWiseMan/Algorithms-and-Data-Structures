#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    char string[1000001];
    gets(string);
    
    int keys[26] = { 0 };
    unsigned int length = strlen(string);
    for(int i = 0; i <= length - 1; i++) keys[ string[i] - 97 ]++;
    
    int indices[26], index = 0;
    for(int i = 0; i <= 25; i++){ indices[i] = keys[i] + index; index += keys[i];}
    
    index = 0;
    int letter = 97;
    for(int i = 0; i <= 25; i++){
        for(int j = index; j <= indices[i] - 1; j++) string[j] = letter;
        if(keys[i] != 0) index = indices[i];
        letter++;
    }
    
    printf("%s\n", string);
    
    return 0;
}
