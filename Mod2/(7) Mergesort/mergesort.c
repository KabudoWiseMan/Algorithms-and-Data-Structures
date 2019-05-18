#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void InsertSort(int*, int, int);
void MergeSort(int*, int);
void Merge(int*, int, int, int);
void MergeSortRec(int*, int, int);

void InsertSort(int *a, int low, int high){
    int i = low + 1;
    while(i < high){
        int elem = a[i];
        int loc = i - 1;
        while( (loc >= 0) && (abs(a[loc]) > abs(elem)) ){
            a[loc + 1] = a[loc];
            loc--;
        }
        a[loc + 1] = elem;
        i++;
    }
}

void Merge(int *numbers, int k, int l, int m){
    int helper[m - k + 1];
    int i = k;
    int j = l + 1;
    int h = 0;
    while(h < m - k + 1){
        if( (j <= m) && ( (i == l + 1) || (abs(numbers[j]) < abs(numbers[i])) ) ){
            helper[h] = numbers[j];
            j++;
        }else{
            helper[h] = numbers[i];
            i++;
        }
        h++;
    }
    int t = 0;
    while( (k <= m) && (t <= h - 1) ){
        numbers[k] = helper[t];
        k++;
        t++;
    }
}

void MergeSort(int *numbers, int n){
    MergeSortRec(numbers, 0, n - 1);
}

void MergeSortRec(int *numbers, int low, int high){
    if(low < high){
        if (high-low <= 3) {
            InsertSort(numbers, low, high + 1);
            return;
        }
        int med = (low + high) / 2;
        MergeSortRec(numbers, low, med);
        MergeSortRec(numbers, med, high);
        Merge(numbers, low, med, high);
    }
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    int numbers[n];
    
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    MergeSort(numbers, n);
    
    for(int i = 0; i <= n - 1; i++) printf("%d ", numbers[i]);
    
    return 0;
}
