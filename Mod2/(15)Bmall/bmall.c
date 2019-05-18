#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a, b) ( ( (a) > (b) )? (a) : (b) )

int *Delta1(char *S, int size){
    int *d1 = (int*)malloc(sizeof(int) * size);
    int a = 0, len_S = strlen(S);
    while(a < size){
        d1[a] = len_S;
        a++;
    }
    int j = 0;
    while(j < len_S){
        d1[S[j]] = len_S - j - 1;
        j++;
    }
    return d1;
}

int *Suffix(char *S){
    int len_S = strlen(S), t;
    int *s = (int*)malloc(sizeof(int) * len_S);
    s[len_S - 1] = t = len_S - 1;
    int i = len_S - 2;
    while(i >= 0){
        while( (t < len_S - 1) && (S[t] != S[i]) ) t = s[t + 1];
        if(S[t] == S[i]) t--;
        s[i] = t;
        i--;
    }
    return s;
}

int *Delta2(char *S){
    int len_S = strlen(S);
    int *d2 = (int*)malloc(sizeof(int) * len_S);
    int *s = Suffix(S);
    int i = 0, t = s[0];
    while(i < len_S){
        while(t < i) t = s[t + 1];
        d2[i] = -i + t + len_S;
        i++;
    }
    i = 0;
    while(i < len_S - 1){
        t = i;
        while(t < len_S - 1){
            t = s[t + 1];
            if(S[i] != S[t]) d2[t] = -(i + 1) + len_S;
        }
        i++;
    }
    free(s);
    return d2;
}

void BMSubst(char *S, int size, char *T){
    int len_S = strlen(S), len_T = strlen(T);
    int *d1 = Delta1(S, size);
    int *d2 = Delta2(S);
    int k = len_S - 1;
    while(k < len_T){
        int i = len_S - 1;
        int flag = 0;
        while(T[k] == S[i]){
            if(i == 0){
                printf("%d ", k);
                k += len_S;
                flag = 1;
                break;
            }
            i--;
            k--;
        }
        if(flag) continue;
        k += max(d1[T[k]], d2[i]);
    }
    k = len_T;
    free(d1);
    free(d2);
}

int main(int argc, char **argv)
{
    BMSubst(argv[1], 256, argv[2]);
    return 0;
}




//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int *stop_symbols(char *s){
//    int MAX = 256;
//    int *p = (int*)malloc(MAX*sizeof(int));
//    int l = strlen(s);
//    for(int i=0; i<MAX; i++) p[i] = l;
//    for(int i=0; i<l; i++) p[s[i]] = l-i-1;
//    return p;
//}
//int *suffix(char *s){
//    int l = strlen(s), t, i;
//    int *p = (int*)malloc(l*sizeof(int));
//    p[l-1] = t = l-1;
//    for(i = l-2; i>=0; i--){
//        while(t < l-1 && s[i]!=s[t]) t = p[t+1];
//        if(s[i]==s[t]) t--;
//        p[i] = t;
//    }
//    return p;
//}
//int *delta(char *s){
//    int l = strlen(s), t;
//    int *p = (int*)malloc(l*sizeof(int));
//    int *si = suffix(s);
//    t = si[0];
//    for(int i = 0; i<l; i++){
//        while(t < i) t = si[t+1];
//        p[i] = t+l-i;
//    }
//    for(int i=0; i<l-1; i++){
//        t=i;
//        while(t < l-1){
//            t = si[t+1];
//            if(s[i]!=s[t])
//                p[t] = l-(i+1);
//        }
//    }
//    free(si);
//    return p;
//}
//void bm(char *s, char *t){
//    int *sym = stop_symbols(s);
//    int *suf = delta(s);
//    int ls = strlen(s);
//    int lt = strlen(t);
//    for(int k = ls-1; k<lt;){
//        int i = ls-1;
//        int flag = 0;
//        while(i>=0 && k>=0 && t[k] == s[i]){
//            if(i == 0){
//                printf("%d ", k);
//                k+=ls;
//                flag = 1;
//                break;
//            }
//            i--;k--;
//        }
//        if(flag) continue;
//        k += (sym[t[k]] > suf[i])?sym[t[k]]:suf[i];
//    }
//    free(sym);
//    free(suf);
//}
//int main(int argc, char **argv){
//    bm(argv[1], argv[2]);
//    return 0;
//}
