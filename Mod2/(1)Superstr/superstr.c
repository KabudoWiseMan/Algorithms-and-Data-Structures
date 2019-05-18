#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct String {
    char string[300];
    int length;
};
int Permut_rec(char *u, int *h, int m, struct String *strings, int **table, int n, int answer) {
    if (m == n) {
        int length = strings[h[0]].length;
        for (int i = 1; i <= n - 1; i++) {
            length += strings[h[i]].length - table[h[i - 1]][h[i]];
        }
        if(length < answer) {
            answer = length;
        }
    } else {
        for (int i = 0; i <= n - 1; i++) {
            if (!u[i]) {
                u[i] = 1;
                h[m] = i;
                answer = Permut_rec(u, h, m + 1, strings, table, n, answer);
                u[i] = 0;
            }
        }
    }
    return answer;
}

int Permut(char *u, int *h, struct String *strings, int **table, int n, int answer) {
    return Permut_rec(u, h, 0, strings, table, n, answer);
}

int main(int argc, char **argv) {
    int n, answer = 32767;
    scanf("%d\n", &n);
    
    struct String *strings = (struct String*)malloc(n * sizeof(struct String));
    for (int i = 0; i < n; i++) {
        scanf("%s", strings[i].string);
        strings[i].length = strlen(strings[i].string);
    }
    
    int **table = (int**)malloc(n * sizeof(int*));
    for(int i = 0; i <= n - 1; i++) {
        table[i] = (int*)malloc(n * sizeof(int));
    }
    
    for(int i = 0; i <= n - 1; i++) {
        for(int j = 0; j <= n - 1; j++) {
            if(i == j) {
                table[i][j] = -1;
            } else {
                int overlap = 0;
                int lenA = strings[i].length;
                for (int k = 1; k <= lenA - 1; k++) {
                    if (!strncmp(strings[i].string + k, strings[j].string, strings[i].length - k)) {
                        overlap = lenA - k;
                        break;
                    } else {
                        overlap = 0;
                    }
                }
                table[i][j] = overlap;
            }
        }
    }
    char u[n];
    int h[n];
    memset(u, 0, n);
    
    answer = Permut(u, h, strings, table, n, answer);
    printf("%d\n", answer);
    
    free(strings);
    for(int i = 0; i <= n - 1; i++) {
        free(table[i]);
    }
    free(table);

    return 0;
}
