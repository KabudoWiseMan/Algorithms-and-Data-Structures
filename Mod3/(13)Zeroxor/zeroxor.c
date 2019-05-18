//
//  zeroxor.c
//  (13)Zeroxor
//
//  Created by Vsevolod Molchanov on 30.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct Elem {
    struct Elem *next;
    int k, v;
};

struct Elem* InitSingleLinkedList() {
    struct Elem *l = (struct Elem*)malloc(sizeof(struct Elem));
    l->next = NULL;
    return l;
}

struct Elem* ListSearch(struct Elem *l, unsigned int k) {
    struct Elem *x = l;
    while(x != NULL && x->k != k) {
        x = x->next;
    }
    return x;
}

void InsertAfter(struct Elem *x, struct Elem *y) {
    struct Elem *z = x->next;
    x->next = y;
    y->next = z;
}

void InsertBeforeHead(struct Elem *l, struct Elem *y) {
    y->next = l;
    l = y;
}

struct Elem** InitHashTable(m) {
    struct Elem **t = (struct Elem**)malloc(m * sizeof(struct Elem*));
    for(int i = 0; i <= m - 1; i++) {
        t[i] = InitSingleLinkedList();
        t[i]->k = -1;
        t[i]->v = 1;
    }
    return t;
}

int h(unsigned int i, int m) {
    return i % m;
}

void Insert(struct Elem **t, int (*h)(int i, int m), unsigned int k, unsigned int v, int m) {
    int i = h(k, m);
    if(ListSearch(t[i], k) != NULL) {
        printf("panic\n");
        exit(1);
    }
    struct Elem *x = InitSingleLinkedList();
    x->v = v;
    x->k = k;
    x->next = NULL;
    InsertAfter(t[i], x);
}

void DeleteAfter(struct Elem *x) {
    struct Elem *y = x->next;
    x->next = y->next;
    y->next = NULL;
    free(y);
}

void DeleteHead(struct Elem *l) {
    struct Elem *y = l;
    l = y->next;
    y->next = NULL;
    free(y);
}

void SearchAndDelete(struct Elem *l, unsigned int k) {
    struct Elem *y = NULL;
    struct Elem *x = l;
    while(x != NULL) {
        if(x->k == k) {
            if(y == NULL) {
                DeleteHead(l);
            } else {
                DeleteAfter(y);
            }
            break;
        }
        y = x;
        x = x->next;
    }
}

void Delete(struct Elem **t, int (*h)(int i, int m), unsigned int k, int m) {
    SearchAndDelete(t[h(k, m)], k);
}

void Reassign(struct Elem **t, int (*h)(int i, unsigned int m), unsigned int k, unsigned int v, int m) {
    struct Elem *p = ListSearch(t[h(k, m)], k);
    if(p == NULL) {
        printf("panic\n");
        exit(1);
    }
    p->v = v;
}

struct Elem* Lookup(struct Elem **t, int (*h)(int i, unsigned int m), unsigned int k, int m) {
    struct Elem *p = ListSearch(t[h(k, m)], k);
    if(p == NULL) {
        return NULL;
    }
    return p;
}

void Assign(struct Elem **t, int (*h)(int i, unsigned int m), unsigned int i, unsigned int v, int m) {
    if(Lookup(t, h, i, m) == NULL) {
        if(v) {
            Insert(t, h, i, v, m);
        } else {
            return;
        }
    } else if(!v) {
        Delete(t, h, i, m);
    } else {
        Reassign(t, h, i, v, m);
    }
}

int At(struct Elem **t, int (*h)(int i, unsigned int m), unsigned int i, int m) {
    struct Elem *value = Lookup(t, h, i, m);
    if(value == NULL) {
        return 0;
    } else {
        return value->v;
    }
}

int main(int argc, const char * argv[]) {
    unsigned int n;
    scanf("%d", &n);
    struct Elem **table = InitHashTable(10000);
    
    unsigned int x = 0;
    long long int result = 0;
    unsigned int *intervals = (unsigned int*)malloc(n * sizeof(unsigned int));
    for(int i = 0; i <= n - 1; i++) {
        unsigned int elem;
        scanf("%d", &elem);
        x ^= elem;
        int isInTable = At(table, h, x, 10000);
        if(!isInTable) {
            if(!x) {
                intervals[i] = 1;
            } else {
                intervals[i] = 0;
            }
            Assign(table, h, x, i + 1, 10000);
        } else {
            intervals[i] = intervals[isInTable - 1] + 1;
            Reassign(table, h, x, i + 1, 10000);
        }
        result += intervals[i];
    }
    printf("%llu\n", result);
    
    
    for(int j = 0; j <= 10000 - 1; j++) {
        struct Elem *a = table[j]->next;
        free(table[j]);
        while(a != NULL) {
            struct Elem *b = a->next;
            free(a);
            a = b;
        }
    }
    free(table);
    free(intervals);
    
    return 0;
}
