#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int CompareSubstrings(char *S, int k, int i){
    int compared = 0, count = 0;
    int j = 0, z = i - k + 1, result = 0;
    while( (j <= k - 1) && (z <= i) ){
        compared++;
        if(S[j] == S[z]) count++;
        j++;
        z++;
    }
    if(compared == count) result = 1;
    return result;
}

int *BruteForcePrefix(char *S){
    int length = strlen(S);
    int *pi = (int*)malloc(length * sizeof(int));
    pi[0] = 0;
    int i = 1;
    while(i < length){
        int k = i;
        while( (k > 0) && ((CompareSubstrings(S, k, i) == 0)) ){
            k--;
        }
        pi[i] = k;
        i++;
    }
    return pi;
}

int main(int argc, char **argv)
{
    char *S = argv[1];
    int length = strlen(S);
    int *pi = BruteForcePrefix(S);
    int n = 0, k = 0;
    for(int i = 0; i <= length - 1; i++){
        if( (pi[i] > 0) && ( (i + 1) % (i + 1 - pi[i]) == 0) ){
            n = i + 1;
            k = (i + 1) / (i + 1 - pi[i]);
            printf("%d %d\n", n, k);
        }
    }
    free(pi);
    return 0;
}
