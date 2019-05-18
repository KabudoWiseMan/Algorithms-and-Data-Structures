#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack{
    struct Task *data;
    int cap;
    int top;
};

int StackEmpty(struct Stack *s){
    int empty = (s->top == 0);
    return empty;
}

void Push(struct Stack *s, struct Task x){
    s->data[s->top] = x;
    s->top++;
}

struct Task Pop(struct Stack *s){
    s->top--;
    return s->data[s->top];
}

void InitStack(struct Stack *s, int n){
    s->data = (struct Task*)malloc(n*sizeof(struct Task));
    s->cap = n;
    s->top = 0;
    struct Task c;
    c.low = 0;
    c.high = n - 1;
    Push(s, c);
}

int Partition(int *array, int low, int high){
    int i = low;
    int j = low;
    while(j < high){
        if(array[j] < array[high]){
            int remember = array[i];
            array[i] = array[j];
            array[j] = remember;
            i++;
        }
        j++;
    }
    int remember = array[i];
    array[i] = array[high];
    array[high] = remember;
    return i;
}

void QuickSort(int *array, int low, int high, struct Stack *stack){
    if(low < high){
        int q = Partition(array, low, high);
        
        struct Task task1, task2;
        task1.low = q + 1;
        task1.high = high;
        task2.low = low;
        task2.high = q - 1;
        Push(stack, task1);
        Push(stack, task2);
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    int *numbers = (int*)malloc(n * sizeof(int));
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    struct Stack stack;
    InitStack(&stack, n);
    
    while(!StackEmpty(&stack)){
        struct Task task = Pop(&stack);
        QuickSort(numbers, task.low, task.high, &stack);
    }
    
    for(int i = 0; i <= n - 1; i++) printf("%d ", numbers[i]);
    
    free(numbers);
    free(stack.data);
    
    return 0;
}
