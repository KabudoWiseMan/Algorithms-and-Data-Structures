#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char **argv)
{
    int k;
    scanf("%d", &k);
    
    int n = 0;
    int *lengths = (int*)malloc(k * sizeof(int));
    for(int i = 0; i <= k - 1; i++){
        scanf("%d", &lengths[i]);
        n += lengths[i];
    }
    
    struct PriorityQueue *q = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    InitPriorityQueue(q, n);
    
    for(int i = 0; i <= k - 1; i++)
        for(int j = 0; j <= lengths[i] - 1; j++){
            int number;
            scanf("%d", &number);
            struct Pointer x;
            x.index = j;
            x.value = number;
            Insert(q, x);
        }
    
    for(int i = 0; i <= n - 1; i++)
        printf("%d ", ExtractMax(q).value);
    
    free(lengths);
    free(q->heap);
    free(q);
    
    return 0;
}
