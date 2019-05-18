#include <stdio.h>

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

void SelectSort(int *array, int low, int high){
    int j = high;
    while(j > low){
        int k = j;
        int i = j - 1;
        while(i >= low){
            if(array[k] < array[i])
                k = i;
            i--;
        }
        int remember = array[j];
        array[j] = array[k];
        array[k] = remember;
        j--;
    }
}

void QuickSort(int *array, int low, int high, int m){
    if(high - low + 1 < m){
        SelectSort(array, low, high);
    }else{
        while(low < high){
            int q = Partition(array, low, high);
            QuickSort(array, low, q - 1, m);
            low = q + 1;
        }
    }
}

int main(int argc, char **argv)
{
    int n, m;
    scanf("%d", &n);
    scanf("%d", &m);
    
    int numbers[n];
    for(int i = 0; i <= n - 1; i++) scanf("%d", &numbers[i]);
    
    QuickSort(numbers, 0, n - 1, m);
    
    for(int i = 0; i <= n - 1; i++) printf("%d ", numbers[i]);
    
    return 0;
}
