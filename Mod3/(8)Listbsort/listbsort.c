//
//  main.c
//  (8)Listbsort
//
//  Created by Vsevolod Molchanov on 07.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct Elem {
    struct Elem *next;
    char *word;
};

void InitSingleLinkedList(struct Elem *l){
    l->next = NULL;
    l->word = (char*)malloc(100 * sizeof(char));
}

int ListLength(struct Elem *l){
    int len = 0;
    struct Elem *x = l;
    while(x != NULL){
        len++;
        x = x->next;
    }
    return len;
}

void InsertAfter(struct Elem *x, struct Elem *y){
    struct Elem *z = x->next;
    x->next = y;
    y->next = z;
}

struct Elem *bsort(struct Elem *list)
{
    int n = ListLength(list);
    int t = n - 2;
    while(t > 0){
        struct Elem *helper = list->next;
        int bound = t;
        t = 0;
        int i = 0;
        while(i < bound){
            if(strlen(helper->next->word) < strlen(helper->word)){
                char remember[100];
                strcpy(remember, helper->word);
                strcpy(helper->word, helper->next->word);
                strcpy(helper->next->word, remember);
                t = i;
            }
            i++;
            helper = helper->next;
        }
    }
    return list;
}

int main(int argc, const char * argv[]) {
    
    struct Elem *l = (struct Elem*)malloc(sizeof(struct Elem));
    InitSingleLinkedList(l);
    
    char *s = (char*)malloc(1000 * sizeof(char));
    gets(s);
    
    int n = strlen(s);
    int i = 0, word = 0, words = 0;
    while (i < n) {
        if( (s[i] != ' ') && (word == 0) )
        {
            word = 1;
            words++;
        }
        else if(s[i] == ' ')
            word = 0;
        i++;
    }
    
    struct Elem *elements = (struct Elem*)malloc(words * sizeof(struct Elem));
    char ss[words][100];
    i = 0;
    int j = 0;
    while(i < n){
        while(s[i] == ' ') i++;
        char elem[100];
        int k = 0;
        while( (s[i] != ' ') && (i < n) ){
            elem[k] = s[i];
            i++;
            k++;
        }
        elem[k] = '\0';
        strcpy(ss[j++], elem);
    }
    
    for(int i = words - 1; i >= 0; i--){
        elements[i].word = ss[i];
        InsertAfter(l, &elements[i]);
    }
    
    l = bsort(l);
    struct Elem *a = l->next;
    while(a != NULL){
        printf("%s ", a->word);
        a = a->next;
    }
    
    free(l->word);
    free(l);
    free(s);
    free(elements);
    
    return 0;
}
