//
//  main.c
//  What's Next
//
//  Created by Vsevolod Molchanov on 17.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int a = 1, b = 1, c = 1;
    while(a != 0 || b != 0 || c != 0){
        
        scanf("%d %d %d", &a, &b, &c);
        if(a == 0 && b == 0 && c == 0) break;
    
        if( a == 0 || b == 0 || c == 0){
            printf("AP %d\n", c - b + c);
            continue;
        }
    
        if(c == b - a + b){
            printf("AP %d\n", c - b + c);
            continue;
        }
    
        printf("GP %d\n", c / b * c);
    }
    
    return 0;
}
