//
//  ptrie.c
//  (14)Ptrie
//
//  Created by Vsevolod Molchanov on 30.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct Tree {
    struct Tree *parent;
    struct Tree **a;
    char end;
    unsigned short count;
};

struct Set {
    struct Tree *x;
    unsigned int i;
};

struct Tree* InitTree() {
    struct Tree* tree = (struct Tree*)malloc(sizeof(struct Tree));
    tree->count = 1;
    tree->end = 1;
    tree->parent = NULL;
    tree->a = (struct Tree**)malloc(26 * sizeof(struct Tree*));
    for(unsigned int i = 0; i <= 25; i++) {
        tree->a[i] = NULL;
    }
    return tree;
}

struct Set Descend(struct Tree *t, char* k) {
    struct Tree *x, *y;
    unsigned int i, length = strlen(k);
    for(x = t, i = 0; i < length; i++) {
        y = x->a[k[i] - 'a'];
        if(y == NULL) {
            break;
        }
        x = y;
    }
    struct Set s;
    s.x = x;
    s.i = i;
    return s;
}

void Insert(struct Tree *t, char *k) {
    struct Set s = Descend(t, k);
    struct Tree *x = s.x;
    unsigned int i = s.i, length = strlen(k);
    if(x->end || i < length) {
        struct Tree *f;
        unsigned int i, length = strlen(k);
        for(f = t, i = 0; i < length; i++) {
            struct Tree *y = f->a[k[i] - 'a'];
            if(y == NULL) {
                break;
            }
            y->count++;
            f = y;
        }

    }
    while(i < length) {
        struct Tree *y = InitTree();
        x->a[k[i] - 'a'] = y;
        y->parent = x;
        x = y;
        i++;
    }
    x->end = 0;
}

void Delete(struct Tree *t, char *k) {
    struct Set s = Descend(t, k);
    struct Tree *x = s.x, *y;
    unsigned int i = s.i, j;
    x->end = 1;
    while(x->parent != NULL && x->end) {
        for(j = 0; j <= 25 && x->a[j] == NULL; j++);
        if(j < 26) {
            break;
        }
        y = x->parent;
        i--;
        y->a[k[i] - 'a'] = NULL;
        free(x->a);
        free(x);
        x = y;
    }
    if(x->parent != NULL) {
        while(x->parent != NULL) {
            x->count--;
            x = x->parent;
        }
    }
}

unsigned short Prefix(struct Tree *t, char *k) {
    struct Tree *x;
    unsigned int i, length = strlen(k);
    for(x = t, i = 0; i < length; i++) {
        struct Tree *y = x->a[k[i] - 'a'];
        if(y == NULL) {
            return 0;
        }
        x = y;
    }
    return x->count;
}

void FreeSet(struct Tree *t) {
    unsigned int i;
    struct Tree *x = t;
    for(i = 0; i <= 25; i++) {
        if(x->a[i] != NULL) {
            FreeSet(x->a[i]);
        }
    }
    free(t->a);
    free(t);
}

int main(int argc, const char * argv[]) {
    unsigned int n;
    scanf("%u", &n);
    struct Tree *tree = InitTree();
    
    char *s = (char*)malloc(10 * sizeof(char));
    char *k = (char*)malloc(100000 * sizeof(char));
    for(unsigned int i = 0; i <= n - 1; i++) {
        scanf("%s %s", s, k);
        if(!strcmp(s, "INSERT")) {
            Insert(tree, k);
        } else if(!strcmp(s, "DELETE")) {
            Delete(tree, k);
        } else if(!strcmp(s, "PREFIX")) {
            printf("%d\n", Prefix(tree, k));
        }
    }
    
    free(s);
    free(k);
    FreeSet(tree);
    
    return 0;
}
