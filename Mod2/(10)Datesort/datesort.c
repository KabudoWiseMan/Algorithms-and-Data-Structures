#include <stdio.h>
#include <stdlib.h>

struct Date {
    int Day, Month, Year;
};

void RadixSort(struct Date *dates, int n){
    int years[61] = { 0 };
    int months[12] = { 0 };
    int days[31] = { 0 };
    for(int i = 0; i <= n - 1; i++){
        years[dates[i].Year - 1970]++;
        months[dates[i].Month - 1]++;
        days[dates[i].Day - 1]++;
    }
    
    int y_indices[61], m_indices[12], d_indices[31];
    int y_index = 0, m_index = 0, d_index = 0;
    for(int i = 0; i <= 60; i++){ y_indices[i] = years[i] + y_index; y_index += years[i]; }
    for(int i = 0; i <= 11; i++){ m_indices[i] = months[i] + m_index; m_index += months[i]; }
    for(int i = 0; i <= 30; i++){ d_indices[i] = days[i] + d_index; d_index += days[i]; }
    
    struct Date *helper = (struct Date*)malloc(sizeof(struct Date) * n);
    
    for(int i = n - 1; i >= 0; i--) helper[--d_indices[dates[i].Day - 1]] = dates[i];
    for(int i = n - 1; i >= 0; i--) dates[--m_indices[helper[i].Month - 1]] = helper[i];
    for(int i = n - 1; i >= 0; i--) helper[--y_indices[dates[i].Year - 1970]] = dates[i];
    for(int i = 0; i <= n - 1; i++) dates[i] = helper[i];
    
    free(helper);
}

int main(int argc, char **argv)
{
    int n;
    scanf("%d", &n);
    
    struct Date *dates = (struct Date*)malloc(sizeof(struct Date) * n);
    for(int i = 0; i <= n - 1; i++)
        scanf("%d %d %d", &dates[i].Year, &dates[i].Month, &dates[i].Day);
    
    RadixSort(dates, n);
    
    for(int i = 0; i <= n - 1; i++)
        printf("%d %d %d\n", dates[i].Year, dates[i].Month, dates[i].Day);
    
    free(dates);
    
    return 0;
}
