#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *Prefix(char *S){
    int len_S = strlen(S);
    int *pi = (int*)malloc(sizeof(int) * len_S);
    int t;
    pi[0] = t = 0;
    int i = 1;
    while(i < len_S){
        while( (t > 0) && (S[t] != S[i]) ) t = pi[t - 1];
        if(S[t] == S[i]) t++;
        pi[i] = t;
        i++;
    }
    return pi;
}

void KMPSubst(char *S, char *T){
    int *pi = Prefix(S);
    int q = 0, k = 0, len_T = strlen(T), len_S = strlen(S);
    while(k < len_T){
        while( (q > 0) && (S[q] != T[k]) ) q = pi[q - 1];
        if(S[q] == T[k]) q++;
        if(q == len_S){
            printf("%d ", k - len_S + 1);
        }
        k++;
    }
    free(pi);
}

int main(int argc, char **argv)
{
    KMPSubst(argv[1], argv[2]);
    return 0;
}
