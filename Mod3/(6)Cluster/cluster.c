//
//  main.c
//  (6)Cluster
//
//  Created by Vsevolod Molchanov on 06.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define max(a, b) ( ( (a) > (b) )? (a) : (b) )

struct Pointer{
    int index;
    int value;
};

struct PriorityQueue{
    struct Pointer *heap;
    int cap;
    int count;
};

void InitPriorityQueue(struct PriorityQueue *q, int n){
    q->heap = (struct Pointer*)malloc(n * sizeof(struct Pointer));
    q->cap = n;
    q->count = 0;
}

void Insert(struct PriorityQueue *q, struct Pointer ptr){
    int i = q->count;
    if(i == q->cap){
        printf("error 'переполнение'");
        return;
    }
    q->count = i + 1;
    q->heap[i] = ptr;
    while( (i > 0) && (q->heap[(i - 1) / 2].value > q->heap[i].value) ){
        struct Pointer remember = q->heap[(i - 1) / 2];
        q->heap[(i - 1) / 2] = q->heap[i];
        q->heap[i] = remember;
        q->heap[i].index = i;
        i = (i - 1) / 2;
    }
    q->heap[i].index = i;
}

void Heapify(int i, int n, struct PriorityQueue *P){
    int l = 2 * i + 1;
    int r = l + 1;
    int j = i;
    if( (r < n) && (P->heap[i].value > P->heap[r].value) ) j = r;
    if( (l < n) && (P->heap[j].value > P->heap[l].value) ) j = l;
    if(i != j){
        struct Pointer remember = P->heap[i];
        P->heap[i] = P->heap[j];
        P->heap[j] = remember;
        P->heap[i].index = i;
        P->heap[j].index = j;
        Heapify(j, n, P);
    }
}

struct Pointer ExtractMax(struct PriorityQueue *q){
    struct Pointer ptr = q->heap[0];
    q->count--;
    if(q->count > 0){
        q->heap[0] = q->heap[q->count];
        q->heap[0].index = 0;
        Heapify(0, q->count, q);
    }
    return ptr;
}

int main(int argc, const char * argv[]) {
    
    int N, M;
    scanf("%d", &N);
    scanf("%d", &M);
    
    struct PriorityQueue *q = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    InitPriorityQueue(q, N);

    int t1, t2, time = 0;
    for(int i = 0; i <= N - 1; i++){
        scanf("%d %d", &t1, &t2);
        struct Pointer x;
        x.index = i;
        x.value = t1 + t2;
        Insert(q, x);
        time = max(x.value, time);
    }

    for(int i = N; i <= M - 1; i++){
        scanf("%d %d", &t1, &t2);
        struct Pointer x;
        x.index = i;
        x.value = ExtractMax(q).value;
        x.value = max(x.value, t1) + t2;
        time = max(x.value, time);
        Insert(q, x);
    }
    
    printf("%d\n", time);
    
    free(q->heap);
    free(q);
    
    return 0;
}
