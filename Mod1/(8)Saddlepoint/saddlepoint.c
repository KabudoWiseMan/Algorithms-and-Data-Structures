#include <stdio.h>

int main(int argc, char **argv)
{
    short number_of_lines, number_of_columns;
    scanf("%hi%hi", &number_of_lines, &number_of_columns);
    short i, j;
    int matrix[number_of_lines][number_of_columns];
    for(i = 0; i <= (number_of_lines - 1); i++)
        for(j = 0; j <= (number_of_columns - 1); j++)
            scanf("%d", &matrix[i][j]);

    int saddlepoint_line = -1, saddlepoint_column = -1, min, max, array_of_max[number_of_lines], array_of_min[number_of_columns];
    for(i = 0; i <= (number_of_lines - 1); i++){
        max = matrix[i][0];
        for(j = 0; j <= (number_of_columns - 1); j++){
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        array_of_max[i] = max;
    }
    for(j = 0; j <= (number_of_columns - 1); j++){
        min = matrix[0][j];
        for(i = 0; i <= (number_of_lines - 1); i++){
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        array_of_min[j] = min;
    }
    
    for(i = 0; i <= (number_of_lines - 1); i++)
        for(j = 0; j <= (number_of_columns -1); j++)
            if(array_of_max[i] == array_of_min[j]){ saddlepoint_line = i; saddlepoint_column = j; }
    if ((saddlepoint_line == -1)||(saddlepoint_column == -1))
        printf("none");
    else
        printf("%d %d\n", saddlepoint_line, saddlepoint_column);
    return 0;
}
