#include <stdio.h>

int main(int argc, char **argv)
{
    long int a, b, m;
    scanf("%ld%ld%ld", &a, &b, &m);
    
    int count = 0;
    long int change_b = b;
    while (change_b != 1){
        change_b = change_b / 2;
        count++;
    }
    
    int b_to_binary[count], i;
    for (i = 0; i <= count; i++){
        b_to_binary[i] = b % 2;
        b = b / 2;
    }
    
    long int modul = (a * b_to_binary[count]) % m;
    for (i = (count - 1); i >= 0; i--){
        modul = modul * 2 + ((a * b_to_binary[i]) % m);
        modul = modul % m;
    }
    printf("%ld\n", modul);
    
    return 0;
}
