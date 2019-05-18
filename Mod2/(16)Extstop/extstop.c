#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int **Delta1(char *S, int size){
    int a = 0, len_S = strlen(S);
    int **matrix = (int**)malloc(sizeof(int*) * len_S);
    for(int i = 0; i <= len_S - 1; i++) matrix[i] = (int*)malloc(sizeof(int) * size);
    while(a < len_S){
        int b = 0;
        while(b < size){
            matrix[a][b] = a + 1;
            b++;
        }
        a++;
    }
    int j = 0;
    while(j < len_S){
        int c = (int)(S[j] - 'a'), k = len_S;
        int d = j + 1;
        while(d < len_S){
            if(c == S[d] - 'a'){
                k = d;
                break;
            }
            d++;
        }
        d = j + 1;
        while(d < k){
            matrix[d][c] = d - j;
            d++;
        }
        j++;
    }
    return matrix;
}

void SimpleBMSubst(char *S, int size, char *T){
    int **matrix = Delta1(S, size);
    int len_S = strlen(S), len_T = strlen(T);
    int k = len_S - 1;
    while(k < len_T){
        int i = len_S - 1;
        int k2 = k;
        while(T[k] == S[i]){
            if(i == 0){
                printf("%d\n", k);
                for(int t = 0; t <= len_S - 1; t++) free(matrix[t]);
                free(matrix);
                return;
            };
            i--;
            k--;
        }
        k = k2 + matrix[i][T[k] - 'a'];
    }
    printf("%d\n", len_T);
    
    for(int i = 0; i <= len_S - 1; i++) free(matrix[i]);
    free(matrix);
}

int main(int argc, char **argv)
{
    SimpleBMSubst(argv[1], 26, argv[2]);
    return 0;
}
