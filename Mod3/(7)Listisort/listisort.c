//
//  main.c
//  (7)Listisort
//
//  Created by Vsevolod Molchanov on 07.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct Elem {
    struct Elem *prev, *next;
    int v;
};

void InitDoubleLinkedList(struct Elem *l)
{
    l->next = l->prev = l;
    l->v = NULL;
}

void InsertAfter(struct Elem *x, struct Elem *y){
    struct Elem *z = x->next;
    x->next = y;
    y->prev = x;
    y->next = z;
    z->prev = y;
}

void Delete(struct Elem *x)
{
    struct Elem *y = x->prev, *z = x->next;
    y->next = z;
    z->prev = y;
    x->prev = NULL;
    x->next = NULL;
}

void InsertSort(struct Elem *l){
    struct Elem *i = l->next;
    while(i != l) {
        struct Elem *loc = i->prev;
        while( (loc != l) && (i->v < loc->v) )
            loc = loc->prev;
        Delete(i);
        InsertAfter(loc, i);
        i = i->next;
        loc = i->prev;
    }
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    struct Elem *l = (struct Elem*)malloc(sizeof(struct Elem));
    InitDoubleLinkedList(l);
    
    int elem;
    struct Elem *element = (struct Elem*)malloc(n * sizeof(struct Elem));
    for(int i = 0; i <= n - 1; i++){
        scanf("%d", &elem);
        element[i].v = elem;
        InsertAfter(l->prev, &element[i]);
    }
    
    InsertSort(l);
    struct Elem *a = l->next;
    while(a != l){
        printf("%d ", a->v);
        a = a->next;
    }
    
    free(l);
    free(element);
    
    return 0;
}
