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
        if(q == 0){
            free(pi);
            printf("no\n");
            return;
        }
        k++;
    }
    free(pi);
    printf("yes\n");
}

int main(int argc, char **argv)
{
    KMPSubst(argv[1], argv[2]);
    return 0;
}



//#include<stdio.h>
//#include<string.h>
//#include<stdlib.h>
//int *prefix(char *s){
//    int l = strlen(s);
//    int *p = (int*)malloc(l*sizeof(int));
//    p[0] = 0;
//    for(int i=1; i<l; i++){
//        int j = p[i-1];
//        while(j > 0 && s[i]!=s[j]) j = p[j-1];
//        if(s[i] == s[j]) ++j;
//        p[i] = j;
//    }
//    return p;
//}
//void kmp(char *s, char *t){
//    int *p = prefix(s);
//    int q=0, lt=strlen(t), ls=strlen(s);
//    for(int i=0; i<lt; i++){
//        while(q > 0 && t[i] != s[q]) q = p[q-1];
//        if(s[q]==t[i]) q++;
//        if(q == 0) {
//            free(p);
//            printf("no");
//            return;
//        }
//    }
//    free(p);
//    printf("yes");
//}
//int main(int argc, char **argv){
//    kmp(argv[1], argv[2]);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//int *Prefix(char *S){
//    int len_S = strlen(S);
//    int *pi = (int*)malloc(sizeof(int) * len_S);
//    int t;
//    pi[0] = t = 0;
//    int i = 1;
//    while(i < len_S){
//        while( (t > 0) && (S[t] != S[i]) ) t = pi[t - 1];
//        if(S[t] == S[i]) t++;
//        pi[i] = t;
//        i++;
//    }
//    return pi;
//}
//
//void KMPSubst(char *S, char *T){
//    int *pi = Prefix(S);
//    int q = 0, k = 0, len_T = strlen(T), len_S = strlen(S);
//    while(k < len_T){
//        while( (q > 0) && (S[q] != T[k]) ) q = pi[q - 1];
//        if(S[q] == T[k]) q++;
//        if(q == len_S){
//            printf("%d ", k - len_S + 1);
//        }
//        k++;
//    }
//    free(pi);
//}
//
//int main(int argc, char **argv)
//{
//    char a[1000], b[1000];
//    KMPSubst(argv[1], argv[2]);
//    return 0;
//}
