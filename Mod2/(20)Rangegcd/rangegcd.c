#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b){
    a = abs(a), b = abs(b);
    return b? gcd(b, a % b) : a;
}

int Computelogarithms(int n)
{
    int i = 1;
    while ((1 << i) <= n)
        i++;
    return --i;
}

int SparseTable_Query(int **ST, int l, int r){
    int j = Computelogarithms(r - l + 1);
    return gcd(ST[l][j], ST[r - (1 << j) + 1][j]);
}

void SparseTable_Build(int n, int **ST){
    int m = Computelogarithms(n) + 1;
    int i = 0;
    int j = 1;
    while(j < m){
        i = 0;
        while(i <= n - (1 << j)){
            ST[i][j] = gcd(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
            i++;
        }
        j++;
    }
}

int main(int argc, char **argv)
{
    unsigned int n;
    scanf("%d", &n);
    
    int **ST = (int**)malloc(sizeof(int*) * (n + 1));
    int M = Computelogarithms(n) + 1;
    for(int i = 0; i <= n - 1; i++) ST[i] = (int*)malloc(sizeof(int) * M);
    int elem;
    for(int i = 0; i <= n - 1; i++){
        scanf("%d", &elem);
        ST[i][0] = elem;
    }
    SparseTable_Build(n, ST);
    
    int m;
    scanf("%d", &m);
    int l, r;
    for(int i = 0; i <= m - 1; i++){
        scanf("%d %d", &l, &r);
        printf("%d\n", SparseTable_Query(ST, l, r));
    }
    
    for(int i = 0; i <= n - 1; i++) free(ST[i]);
    free(ST);
    
    return 0;
}
