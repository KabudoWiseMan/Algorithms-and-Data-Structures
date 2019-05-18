#include <stdio.h>
#include <stdlib.h>
#define min(a, b) ( ( (a) < (b) )? (a) : (b) )

void FenwickTree_Update(int n, int i, int d, int *T){
    while(i < n){
        T[i] += d;
        i = i | (i + 1);
    }
}

int query(int *T, int i){
    int v = 0;
    while(i >= 0){
        v += T[i];
        i = (i & (i + 1)) - 1;
    }
    return v;
}

int FenwickTree_Query(int *T, int l, int r){
    int v = query(T, r) - query(T, l - 1);
    return v;
}

int is_peak(int *A, int n, int i){
    if((i - 1 >= 0 && i + 1 < n && A[i - 1] <= A[i] && A[i + 1] <= A[i]) ||
       (i == 0 && i + 1 < n && A[i] >= A[i + 1]) ||
       (i == 0 && i == n-1) ||
       (i >= 0 && i + 1 >= n && A[i] >= A[i - 1]))
        return 1;
    else
        return 0;
}

int build(int *A, int n, int l, int r, int *T){
    int sum = 0;
    int bound = min(r, n);
    while(l < bound){
        int m = l + (r - l) / 2;
        sum += build(A, n, l, m, T);
        l = m + 1;
    }
    if(r < n){
        sum += is_peak(A, n, r);
        T[r] = sum;
    }
    return sum;
}

void FenwickTree_Build(int *numbers, int n, int *T){
    int r = 1;
    while(r < n) r = (r << 1);
    build(numbers, n, 0, r - 1, T);
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    int *numbers = (int*)malloc(n * sizeof(int));
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    int *tree = (int*)malloc(n * sizeof(int));
    FenwickTree_Build(numbers, n, tree);
    
    int m;
    scanf("%d", &m);
    
    char *s = (char*)malloc(10 * sizeof(char));
    int l, r, t1 = 0, t2 = 0, t3 = 0;
    for(int i = 0; i <= m - 1; i++){
        scanf("%s %d %d", s, &l, &r);
        if(s[0] == 'P') printf("%d\n", FenwickTree_Query(tree, l, r));
        else{
            if (l != n - 1)
                t1 = is_peak(numbers, n, l + 1);
            if (l != 0)
                t2 = is_peak(numbers, n, l - 1);
            t3 = is_peak(numbers, n, l);
            numbers[l] = r;
            FenwickTree_Update(n, l, is_peak(numbers, n, l) - t3, tree);
            if (l != n - 1)
                FenwickTree_Update(n, l + 1, is_peak(numbers, n, l + 1) - t1, tree);
            if (l != 0)
                FenwickTree_Update(n, l - 1, is_peak(numbers, n, l - 1) - t2, tree);
        }
    }
    
    free(numbers);
    free(tree);
    free(s);
    
    return 0;
}
