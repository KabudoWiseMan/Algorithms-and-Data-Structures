#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int query(int *T, int i) {
    int v = 0;
    while(i >= 0) {
        v ^= T[i];
        i = (i & (i + 1)) - 1;
    }
    return v;
}

int FenwickTree_Query(int *T, int l, int r) {
    int v = query(T, r) ^ query(T, l - 1);
    return v;
}

void FenwickTree_Update(int i, char *S, int *T, int n, char *s) {
    int length = strlen(s);
    for(int j = 0; j <= length - 1; j++) {
        int a = (1 << (s[j] - 'a')) ^ (1 << (S[i] - 'a'));
        S[i] = s[j];
        i++;
        int k = i - 1;
        while(k < n) {
            T[k] ^= a;
            k |= (k + 1);
        }
    }
}

void build(char *S, int l, int r, int n, int *T) {
    for (int i = 0; i <= n - 1; i++) {
        T[i] = 0;
    }
    for (int i = 0; i <= n - 1; i++) {
        int j = i;
        while(j < n) {
            T[j] ^= (1 << (S[i] - 'a'));
            j |= (j + 1);
        }
    }
}

void FenwickTree_Build(char *string, int n, int *tree) {
    int r = 1;
    while(r < n) r = (r << 1);
    build(string, 0, r - 1, n, tree);
}

int main(int argc, char **argv) {
    char *string = (char*)malloc(1000010 * sizeof(char));
    gets(string);
    
    int n = strlen(string);
    int *tree = (int*)malloc(2 * n * sizeof(int));
    FenwickTree_Build(string, n, tree);
    
    int m;
    scanf("%d", &m);
    char *str = (char*)malloc(10 * sizeof(char));
    char *s = (char*)malloc(1000010 * sizeof(char));
    for(int j = 0; j <= m - 1; j++){
        scanf("%s", str);
        if(!strcmp(str, "HD")) {
            int l, r;
            scanf("%d %d", &l, &r);
            int f = FenwickTree_Query(tree, l, r);
            int a = 0;
            for(int i = 0; i <= 25; i++) {
                if((f & (1 << i)) > 0) {
                    a++;
                }
                if(a > 1) {
                    printf("NO\n");
                    break;
                }
                if(i == 25) {
                    printf("YES\n");
                }
            }
        } else {
            int i;
            scanf("%d %s", &i, s);
            FenwickTree_Update(i, string, tree, n, s);
        }
    }
    
    free(string);
    free(str);
    free(s);
    free(tree);
    
    return 0;
}
