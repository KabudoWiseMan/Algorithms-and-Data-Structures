//
//  main.c
//  Tiles
//
//  Created by Vsevolod Molchanov on 17.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#define max(a, b) ( ( (a) > (b) )? (a) : (b) )

unsigned long long gcd(unsigned long long a, unsigned long long b){
    while(a != 0 && b != 0){
        if(a > b) a %= b;
        else b %= a;
    }
    return max(a, b);
}

unsigned long long lcm(unsigned long long a, unsigned long long b){
    return a * b / gcd(a, b);
}

unsigned long long tiles(unsigned long long a, unsigned long long b){
    unsigned long long g = gcd(a, b), l = lcm(a, b);
    if(a == b) return 1;
    else if(g < l && g != 1) return g;
    return l;
}

int main(int argc, const char * argv[]) {
    
    unsigned long long W, H;
    scanf("%llu %llu", &W, &H);
    
    if(W == 0 || H == 0) printf("%d\n", 0);
    else{ if(W % H == 0) printf("%llu\n", W / H);
        else{ if(H % W == 0) printf("%llu\n", H / W);
            else printf("%llu\n", tiles(W, H));
        }
    }
    return 0;
}
