#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "elem.h"

struct Elem *searchlist(struct Elem *list, int k)
{
    if( (list->tag == INTEGER) && (list->value.i == k) )
        return list;
    if( (list->tag == FLOAT) && (list->value.f == k) )
        return list;
    if( (list->tag == LIST) && (list->value.list != NULL) ){
        void *after_list = list->tail;
        struct Elem *list_elem = searchlist(list->value.list, k);
        if(list_elem == NULL) return searchlist(after_list, k);
        return list_elem;
    }
    if(list->tail != NULL)
        return searchlist(list->tail, k);
    return NULL;
}

//struct Elem *searchlist(struct Elem *list, int k){
//    if(list->tag == LIST && list->value.list != NULL){
//        struct Elem *ex = searchlist(list->value.list, k);
//        if(ex != NULL) return ex;
//    }
//    if((list->tag == INTEGER) &&(list->value.i == k))
//        return list;
//    if(list->tail != NULL)
//        return searchlist(list->tail, k);
//    return NULL;
//}

struct Elem *searchlist(struct Elem*, int);

int main()
{
    struct Elem e11;
    e11.tag = INTEGER;
    e11.value.i = 80;
    e11.tail = NULL;
    
    struct Elem e13;
    e13.tag = FLOAT;
    e13.value.f = 3.14;
    e13.tail = NULL;
    
    struct Elem e12;
    e12.tag = INTEGER;
    e12.value.i = 100;
    e12.tail = &e13;
    
    struct Elem e10;
    e10.tag = LIST;
    e10.value.list = &e11;
    e10.tail = &e12;
    
    struct Elem e9;
    e9.tag = FLOAT;
    e9.value.f = 3e8;
    e9.tail = &e10;
    
    struct Elem e8;
    e8.tag = INTEGER;
    e8.value.i = 20;
    e8.tail = &e9;
    
    struct Elem e7;
    e7.tag = FLOAT;
    e7.value.f = 3.14;
    e7.tail = &e8;
    
    struct Elem e6;
    e6.tag = INTEGER;
    e6.value.i = 50;
    e6.tail = &e7;
    
    struct Elem e19;
    e19.tag = INTEGER;
    e19.value.i = 10;
    e19.tail = NULL;
    
    struct Elem e18;
    e18.tag = INTEGER;
    e18.value.i = 70;
    e18.tail = &e19;
    
    struct Elem e23;
    e23.tag = INTEGER;
    e23.value.i = 30;
    e23.tail = NULL;
    
    struct Elem e21;
    e21.tag = LIST;
    e21.value.list = NULL;
    e21.tail = &e23;
    
    struct Elem e17;
    e17.tag = LIST;
    e17.value.list = &e18;
    e17.tail = &e21;
    
    struct Elem e16;
    e16.tag = FLOAT;
    e16.value.f = 10.5e-5;
    e16.tail = &e17;
    
    struct Elem e15;
    e15.tag = FLOAT;
    e15.value.f = 3e8;
    e15.tail = &e16;
    
    struct Elem e5;
    e5.tag = LIST;
    e5.value.list = &e6;
    e5.tail = &e15;
    
    struct Elem e4;
    e4.tag = FLOAT;
    e4.value.f = 2.5;
    e4.tail = &e5;
    
    struct Elem e3;
    e3.tag = FLOAT;
    e3.value.f = 2.5;
    e3.tail = &e4;
    
    struct Elem e2;
    e2.tag = FLOAT;
    e2.value.f = 3.14;
    e2.tail = &e3;
    
    struct Elem e1;
    e1.tag = FLOAT;
    e1.value.f = 2.5;
    e1.tail = &e2;
    
    struct Elem e0;
    e0.tag = FLOAT;
    e0.value.f = 3.14;
    e0.tail = &e1;
    
    struct Elem *x = searchlist(&e0, 100);
    if (x == &e12) {
        printf("CORRECT\n");
    } else {
        /* Если функция searchlist работает правильно,
         сюда никогда не будет передано управление! */
        printf("WRONG\n");
    }
    
    return 0;
}
