#include <stdio.h>

int main(int argc, char **argv)
{
    int A, number_A, pow_A = 1, set_A = 0, if_there_0_in_A = 0, i, j;
    scanf("%d", &A);
    for(i = 0; i <= A - 1; i++){
        scanf("%d", &number_A);
        pow_A = 1;
        if(number_A == 0){
            if_there_0_in_A = 1;
            pow_A = 0;
        }
        for(j = 0; j <= number_A - 2; j++){
            pow_A *= 2;
        }
        set_A += pow_A;
    }
    
    int B, number_B, pow_B = 1, set_B = 0, if_there_0_in_B = 0;
    scanf("%d", &B);
    for(i = 0; i <= B - 1; i++){
        scanf("%d", &number_B);
        pow_B = 1;
        if(number_B == 0){
            if_there_0_in_B = 1;
            pow_B = 0;
        }
        for(j = 0; j <= number_B - 2; j++){
            pow_B *= 2;
        }
        set_B += pow_B;
    }
    
    if((if_there_0_in_A == if_there_0_in_B)&&(if_there_0_in_A == 1)&&(if_there_0_in_B == 1)) printf("%d ", 0);
    
    int intersection = set_A & set_B;
    
    
    for(i = 0; i <= 31; i++)
        if(((intersection >> i) & 1) == 1) printf("%d ", i + 1);
    
    return 0;
}

