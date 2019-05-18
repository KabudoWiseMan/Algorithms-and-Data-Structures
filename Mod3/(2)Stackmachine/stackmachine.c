#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct Stack{
    int *data;
    int cap;
    int top;
};

void InitStack(struct Stack *s, int n){
    s->data = (int*)malloc(n*sizeof(int));
    s->cap = n;
    s->top = 0;
}

int StackEmpty(struct Stack *s){
    int empty = (s->top == 0);
    return empty;
}

void Push(struct Stack *s, int x){
    if(s->top == s->cap){
        printf("error 'переполнение'");
        return;
    }
    s->data[s->top] = x;
    s->top++;
}

int Pop(struct Stack *s){
    if(StackEmpty(s)){
        printf("error 'опустошение'");
        return NULL;
    }
    s->top--;
    return s->data[s->top];
}

void Dup(struct Stack *s){
    int elem = Pop(s);
    Push(s, elem);
    Push(s, elem);
}

void Swap(struct Stack *s){
    int a = Pop(s);
    int b = Pop(s);
    Push(s, a);
    Push(s, b);
}

int max(int a, int b){
    return (a > b)? a : b;
}
int min(int a, int b){
    return (a < b)? a : b;
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    struct Stack stack;
    InitStack(&stack, n);
    
    char *s = (char*)malloc(10 * sizeof(char));
    for(int i = 0; i <= n - 1; i++){
        scanf("%s", s);
        if(!strcmp(s, "CONST")){
            int x;
            scanf("%d", &x);
            Push(&stack, x);
        }
        if(!strcmp(s, "ADD"))
            Push(&stack, Pop(&stack) + Pop(&stack));
        if(!strcmp(s, "SUB"))
            Push(&stack, Pop(&stack) - Pop(&stack));
        if(!strcmp(s, "MUL"))
            Push(&stack, Pop(&stack) * Pop(&stack));
        if(!strcmp(s, "DIV"))
            Push(&stack, Pop(&stack) / Pop(&stack));
        if(!strcmp(s, "MAX"))
            Push(&stack, max(Pop(&stack), Pop(&stack)));
        if(!strcmp(s, "MIN"))
            Push(&stack, min(Pop(&stack), Pop(&stack)));
        if(!strcmp(s, "NEG"))
            Push(&stack, -Pop(&stack));
        if(!strcmp(s, "DUP"))
            Dup(&stack);
        if(!strcmp(s, "SWAP")){
            Swap(&stack);
        }
    }
    
    printf("%d\n", Pop(&stack));
    
    free(stack.data);
    free(s);
    
    return 0;
}
