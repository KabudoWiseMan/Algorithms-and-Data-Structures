#include <stdio.h>
#include <string.h>

int strdiff(char *a, char *b)
{
    int bit = 0, was_break = 0;
    int i = 0, a_len = strlen(a), b_len = strlen(b);
    while( (i <= a_len - 1) || (i <= b_len - 1) ){
        for(int j = 0; j <= 7; j++){
            int a_bit = ((int)a[i] & 1 << j)? 1 : 0;
            int b_bit = ((int)b[i] & 1 << j)? 1 : 0;
            if(a_bit != b_bit){
                was_break = 1;
                break;
            }
            bit++;
        }
        if(was_break) break;
        i++;
    }
    if( ( (bit == a_len * 8) || (bit == b_len * 8) ) && (bit != 0) && (a_len == b_len) ) return -1;
    return bit;
}

int strdiff(char *a, char *b);

int main(int argc, char **argv)
{
    char s1[1000], s2[1000];
    gets(s1);
    gets(s2);
    printf("%d\n", strdiff(s1, s2));
    
    return 0;
}
