#include <stdio.h>
#include <string.h>

int compare(const void *one_str, const void *another_str){
    int count_a_in_one = 0, count_a_in_another = 0;
    for(int i = 0; i <= strlen(one_str) - 1; i++)
        if(*((char*)one_str + i) == 'a') count_a_in_one++;
    for(int i = 0; i <= strlen(another_str) - 1; i++)
        if(*((char*)another_str + i) == 'a') count_a_in_another++;
    if(count_a_in_one > count_a_in_another) return 1;
    if(count_a_in_one < count_a_in_another) return -1;
    return 0;
}

void swap(char *a, char *b, int width){
    for(int i = 0; i <= width - 1; i++){
        int remember = *(a + i);
        *(a + i) = *(b + i);
        *(b + i) = remember;
    }
}

void Heapify(void *strings, int i, int n, int width, int (*compare)(const void *a, const void *b)){
    int l = 2 * i + 1;
    int r = l + 1;
    int j = i;
    if( (r < n) && (compare(((char*)strings + i * width), ((char*)strings + r * width)) == -1) ) j = r;
    if( (l < n) && (compare(((char*)strings + j * width), ((char*)strings + l * width)) == -1) ) j = l;
    if(i != j){
        swap((char*)strings + i * width, (char*)strings + j * width, width);
        Heapify(strings, j, n, width, compare);
    }
}

void BuildHeap(void *strings, int n, int width, int (*compare)(const void *a, const void *b)){
    int i = n / 2 - 1;
    while(i >= 0){
        Heapify(strings, i, n, width, compare);
        i--;
    }
}

void hsort(void *base, size_t nel, size_t width,
           int (*compare)(const void *a, const void *b))
{
    BuildHeap(base, nel, width, compare);
    int i = nel - 1;
    while(i > 0){
        swap(base, base + i * width, width);
        Heapify(base, 0, i, width, compare);
        i--;
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d\n", &n);
    
    char strings[n][1000];
    for(int i = 0; i <= n - 1; i++) gets(strings[i]);
    
    hsort(strings, n, 1000, compare);
    
    for(int i = 0; i <= n - 1; i++) printf("%s\n", strings[i]);
    
    return 0;
}
