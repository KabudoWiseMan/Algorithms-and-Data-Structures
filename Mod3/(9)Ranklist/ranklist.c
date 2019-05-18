//
//  ranklist.c
//  (9)Ranklist
//
//  Created by Vsevolod Molchanov on 08.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

struct SkipList {
    int k;
    int *span;
    char *v;
    struct SkipList **next;
};

void InitSkipList(struct SkipList *l, int m) {
    l->next = (struct SkipList**)malloc(m * sizeof(struct SkipList*));
    l->span = (int*)malloc(m * sizeof(int));
    int i = 0;
    while(i < m) {
        l->next[i] = NULL;
        l->span[i] = 0;
        i++;
    }
}

struct SkipList* Succ(struct SkipList *x) {
    struct SkipList *y = x->next[0];
    return y;
}

struct SkipList** Skip(struct SkipList *l, int m, int k, struct SkipList **p) {
    struct SkipList *x = l;
    int i = m - 1;
    while(i >= 0){
        while( (x->next[i] != NULL) && (x->next[i]->k < k) ) {
            x = x->next[i];
        }
        p[i] = x;
        i--;
    }
    return p;
}

char* Lookup(struct SkipList *l, int m, int k) {
    struct SkipList **p = (struct SkipList**)malloc(m * sizeof(struct SkipList*));
    p = Skip(l, m, k, p);
    struct SkipList *x = Succ(p[0]);
    free(p);
    return x->v;
}

void Insert(struct SkipList *l, int m, int k, struct SkipList *x) {
    struct SkipList *helper = l;
    int *rank = (int*)malloc(m * sizeof(int));
    int i = m - 1;
    while(i >= 0) {
        rank[i] = (i == m - 1 ? 0 : rank[i+1]);
        while(helper->next[i] != NULL && helper->next[i]->k < k) {
            rank[i] += helper->span[i];
            helper = helper->next[i];
        }
        i--;
    }
    struct SkipList **p = (struct SkipList**)malloc(m * sizeof(struct SkipList*));
    p = Skip(l, m, k, p);
    int r = rand() * 2;
    i = 0;
    while( (i < m) && (r % 2 == 0) ) {
        x->next[i] = p[i]->next[i];
        p[i]->next[i] = x;
        int temp = rank[0] - rank[i];
        x->span[i] = p[i]->span[i] - temp;
        p[i]->span[i] = temp + 1;
        i++;
        r /= 2;
    }
    while(i < m) {
        ++p[i]->span[i];
        x->next[i] = NULL;
        i++;
    }
    
    free(rank);
    free(p);
}

void Delete(struct SkipList *l, int m, int k) {
    struct SkipList **p = (struct SkipList**)malloc(m * sizeof(struct SkipList*));
    p = Skip(l, m, k, p);
    struct SkipList *x = Succ(p[0]);
    int i = 0;
    while( (i < m) && (p[i]->next[i] == x) ) {
        p[i]->span[i] += x->span[i] - 1;
        p[i]->next[i] = x->next[i];
        i++;
    }
    int j = i;
    while(j < m) {
        p[j]->span[j]--;
        j++;
    }
    free(p);
}

int Rank(struct SkipList *l, int m, int k) {
    struct SkipList *x = l;
    int i = m - 1, result = 0;
    while(i >= 0) {
        while( (x->next[i] != NULL) && (x->next[i]->k < k) ) {
            result += x->span[i];
            x = x->next[i];
        }
        i--;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    int m = (int)log(n) + 1;
    
    struct SkipList *l = (struct SkipList*)malloc(sizeof(struct SkipList));
    InitSkipList(l, m);
    struct SkipList *element = (struct SkipList*)malloc(n * sizeof(struct SkipList));
    
    char *s = (char*)malloc(10 * sizeof(char));
    int k;
    int j = 0;
    for(int i = 0; i <= n - 1; i++) {
        scanf("%s %d", s, &k);
        if(!strcmp(s, "INSERT")) {
            char v[10];
            scanf("%s", v);
            element[j].k = k;
            element[j].v = (char*)malloc(10 * sizeof(char));
            element[j].next = (struct SkipList**)malloc(m * sizeof(struct SkipList*));
            element[j].span = (int*)malloc(m * sizeof(int));
            strcpy(element[j].v, v);
            Insert(l, m, k, &element[j]);
            j++;
        } else if(!strcmp(s, "LOOKUP")) {
            printf("%s\n", Lookup(l, m, k));
        } else if(!strcmp(s, "DELETE")) {
            Delete(l, m, k);
        } else if(!strcmp(s, "RANK")) {
            printf("%d\n", Rank(l, m, k));
        }
    }
    
    free(s);
    free(l->next);
    free(l->span);
    free(l);
    for(int i = 0; i <= j - 1; i++) {
        free(element[i].v);
        free(element[i].next);
        free(element[i].span);
    }
    free(element);
    
    return 0;
}
