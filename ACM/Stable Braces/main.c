//
//  main.c
//  Stable Braces
//
//  Created by Vsevolod Molchanov on 17.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    
    char s[2010];
    gets(s);
    int length = strlen(s), left_braces = 0, right_braces = 0, operations = 0;
    for(int i = 0; i <= length - 1; i++){
        if(s[i] == '{'){
            left_braces++;
            continue;
        }
        if(left_braces > 0){
            left_braces--;
            continue;
        }
        right_braces++;
    }
    operations = left_braces / 2 + right_braces / 2 + left_braces % 2 + right_braces % 2;
    printf("%d\n", operations);
    
    return 0;
}

//#include <stdio.h>
//#include <string.h>
//
//#define maxn 2010
//
//char str[maxn];
//
//int main() {
//    int i, left, op, cas = 1;
//    while(scanf("%s", str), str[0] != '-') {
//        left = op = 0;
//        for(i = 0; str[i]; ++i) {
//            if(str[i] == '{') ++left;
//            else if(0 == left) {
//                ++left; ++op;
//            } else --left;
//        }
//        op += left / 2;
//        printf("%d. %d\n", cas++, op);
//    }
//    return 0;
//}
