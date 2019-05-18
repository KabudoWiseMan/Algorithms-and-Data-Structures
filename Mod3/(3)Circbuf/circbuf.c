#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue{
    int *data;
    int cap;
    int count;
    int head;
    int tail;
};

void InitQueue(struct Queue *q){
    q->data = (int*)malloc(4 * sizeof(int));
    q->cap = 4;
    q->count = 0;
    q->head = 0;
    q->tail = 0;
}

int QueueEmpty(struct Queue *q){
    int empty = (q->count == 0);
    return empty;
}

void Enqueue(struct Queue *q, int x){
    if(q->count == q->cap){
        q->data = (int*)realloc(q->data, q->cap * 2 * sizeof(int));
        for(int i = q->head, j = q->cap + q->head; i <= q->cap - 1; i++, j++)
            q->data[j] = q->data[i];
        q->head += q->cap;
        q->cap *= 2;
    }
    q->data[q->tail] = x;
    q->tail++;
    if(q->tail == q->cap) q->tail = 0;
    q->count++;
}

int Dequeue(struct Queue *q){
    int x = q->data[q->head];
    q->head++;
    if(q->head == q->cap)
        q->head = 0;
    q->count--;
    
    return x;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    struct Queue queue;
    InitQueue(&queue);
    
    char *s = (char*)malloc(10 * sizeof(char));
    int x;
    for(int i = 0; i <= n - 1; i++){
        scanf("%s", s);
        if(!strcmp(s, "ENQ")){
            scanf("%d", &x);
            Enqueue(&queue, x);
        }
        if(!strcmp(s, "EMPTY")){
            if(QueueEmpty(&queue)) printf("true\n");
            else printf("false\n");
        }
        if(!strcmp(s, "DEQ"))
            printf("%d\n", Dequeue(&queue));
    }
    
    free(queue.data);
    free(s);
    
    return 0;
}
