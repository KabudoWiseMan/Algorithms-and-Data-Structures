#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ( ( (a) > (b) )? (a) : (b) )

int query(int *T, int id, int l, int r, int a, int b){
    if( (l == a) && (r == b) ) return T[id];
    else{
        int m = (a + b) / 2;
        if(r <= m) return query(T, id * 2 + 1, l, r, a, m);
        else if(l > m) return query(T, id * 2 + 2, l, r, m + 1, b);
        else return max(query(T, id * 2 + 1, l, m, a, m), query(T, id * 2 + 2, m + 1, r, m + 1, b));
    }
    return 0;
}

void build(int *A, int id, int a, int b, int *T){
    if(a == b){
        T[id] = A[a];
        return;
    }else{
        int m = (a + b) / 2;
        build(A, id * 2 + 1, a, m, T);
        build(A, id * 2 + 2, m + 1, b, T);
        T[id] = max(T[id * 2 + 1],T[id * 2 + 2]);
    }
}

void update(int *T, int id, int i, int v, int a, int b){
    if(a == b){
        T[id] = v;
        return;
    }else{
        int m = (a + b) / 2;
        if(i <= m) update(T, id * 2 + 1, i, v, a, m);
        else update(T, id * 2 + 2, i, v, m + 1, b);
    }
    T[id] = max(T[id * 2 + 1], T[id * 2 + 2]);
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    int *numbers = (int*)malloc(n * sizeof(int));
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    int *tree = (int*)malloc((4 * n - 1) * sizeof(int));
    build(numbers, 0, 0, n - 1, tree);
    
    int m;
    scanf("%d", &m);
    int l, r;
    char *s = (char*)malloc(4 * sizeof(char));
    for(int i = 0; i <= m - 1; i++){
        scanf("%s %d %d", s, &l, &r);
        if(s[0] == 'U'){
            update(tree, 0, l, r, 0, n - 1);
            continue;
        }
        printf("%d\n", query(tree, 0, l, r, 0, n - 1));
    }
    
    free(numbers);
    free(tree);
    free(s);
    
    return 0;
}
