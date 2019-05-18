#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct DoubleStack{
    int *data;
    int cap;
    int top1;
    int top2;
    int *max;
    int top_m;
    int loc_max;
};

void InitDoubleStack(struct DoubleStack *s, int n){
    s->data = (int*)malloc(n * sizeof(int));
    s->cap = n;
    s->top1 = 0;
    s->top2 = n - 1;
    s->max = (int*)malloc(n * sizeof(int));
    s->top_m = n - 1;
    s->loc_max = -2000000001;
}

int StackEmpty1(struct DoubleStack *s){
    int empty = (s->top1 == 0);
    return empty;
}

int StackEmpty2(struct DoubleStack *s){
    int empty = (s->top2 == s->cap - 1);
    return empty;
}

void Push1(struct DoubleStack *s, int x){
    if(s->top2 < s->top1){
        printf("error 'переполнение'");
        return;
    }
    s->data[s->top1] = x;
    s->top1++;
}

void Push2(struct DoubleStack *s, int x){
    if(s->top2 < s->top1){
        printf("error 'переполнение'");
        return;
    }
    s->data[s->top2] = x;
    s->top2--;
}

int Pop1(struct DoubleStack *s){
    if(StackEmpty1(s)){
        printf("error 'опустошение'");
        return NULL;
    }
    s->top1--;
    return s->data[s->top1];
}

int Pop2(struct DoubleStack *s){
    if(StackEmpty2(s)){
        printf("error 'опустошение'");
        return NULL;
    }
    s->top2++;
    return s->data[s->top2];
}

void InitQueueOnStack(struct DoubleStack *s, int n){
    InitDoubleStack(s, n);
}

int QueueEmpty(struct DoubleStack *s){
    int empty = StackEmpty1(s) && StackEmpty2(s);
    return empty;
}

void Enqueue(struct DoubleStack *s, int x){
    Push1(s, x);
    if(x > s->loc_max) s->loc_max = x;
}

int max(int a, int b){
    return a > b ? a : b;
}

int Dequeue(struct DoubleStack *s){
    if(StackEmpty2(s)){
        while(!StackEmpty1(s)){
            int x = Pop1(s);
            Push2(s, x);
            if(s->top_m == s->cap - 1)
                s->max[s->top_m] = x;
            else
                s->max[s->top_m] = max(s->max[s->top_m+1], x);
            s->top_m--;
        }
        s->loc_max = -2000000001;
    }
    s->top_m++;
    return Pop2(s);
}

int Maximum(struct DoubleStack *s){
    if(s->top_m == s->cap - 1) return s->loc_max;
    return max(s->max[s->top_m+1], s->loc_max);
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    struct DoubleStack queue;
    InitQueueOnStack(&queue, n);
    
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
        if(!strcmp(s, "MAX"))
            printf("%d\n", Maximum(&queue));
    }
    
    free(queue.data);
    free(queue.max);
    free(s);
    return 0;
}
