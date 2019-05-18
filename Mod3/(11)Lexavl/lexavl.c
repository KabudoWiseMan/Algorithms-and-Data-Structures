//
//  lexavl.c
//  (11)Lexavl
//
//  Created by Vsevolod Molchanov on 28.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct AVLTree {
    char *k;
    int v, balance;
    struct AVLTree *parent;
    struct AVLTree *left, *right;
};

struct AVLTree* InitBinarySearchTree(struct AVLTree *t) {
    t = NULL;
    return t;
}

struct AVLTree* Descend(struct AVLTree *t, char *k) {
    struct AVLTree *x = t;
    while(x != NULL) {
        char comp = strcmp(k, x->k);
        if(!comp) {
            break;
        }
        if(comp < 0) {
            x = x->left;
        }else{
            x = x->right;
        }
    }
    return x;
}

struct AVLTree* Insert(struct AVLTree *t, char *k, struct AVLTree *y) {
    if(t == NULL) {
        t = y;
    }else{
        struct AVLTree *x = t;
        int true = 1;
        while(true) {
            char comp = strcmp(k, x->k);
            if(!comp) {
                printf("panic\n");
                exit(1);
            }
            if(comp < 0) {
                if(x->left == NULL) {
                    x->left = y;
                    y->parent = x;
                    break;
                }
                x = x->left;
            }else{
                if(x->right == NULL) {
                    x->right = y;
                    y->parent = x;
                    break;
                }
                x = x->right;
            }
        }
    }
    return t;
}

struct AVLTree* ReplaceNode(struct AVLTree *t, struct AVLTree *x, struct AVLTree *y) {
    if(x == t) {
        t = y;
    }else{
        struct AVLTree *p = x->parent;
        if(y != NULL) {
            y->parent = p;
        }
        if(p->left == x) {
            p->left = y;
        }else{
            p->right = y;
        }
    }
    return t;
}

struct AVLTree* RotateLeft(struct AVLTree *t, struct AVLTree *x)
{
    struct AVLTree *y = x->right;
    if(y == NULL) {
        printf("panic\n");
        exit(1);
    }
    t = ReplaceNode(t, x, y);
    struct AVLTree *b = y->left;
    if(b != NULL) {
        b->parent = x;
    }
    x->right = b;
    x->parent = y;
    y->left = x;
    x->balance--;
    if(y->balance > 0) {
        x->balance -= y->balance;
    }
    y->balance--;
    if(x->balance < 0) {
        y->balance += x->balance;
    }
    return t;
}

struct AVLTree* RotateRight(struct AVLTree *t, struct AVLTree *x)
{
    struct AVLTree *y = x->left;
    if(y == NULL) {
        printf("panic\n");
        exit(1);
    }
    t = ReplaceNode(t, x, y);
    struct AVLTree *b = y->right;
    if(b != NULL) {
        b->parent = x;
    }
    x->left = b;
    x->parent = y;
    y->right = x;
    x->balance++;
    if(y->balance < 0) {
        x->balance -= y->balance;
    }
    y->balance++;
    if(x->balance > 0) {
        y->balance += x->balance;
    }
    return t;
}

struct AVLTree* InsertAVL(struct AVLTree *t, char *k, struct AVLTree *v)
{
    struct AVLTree *a = Insert(t, k, v);
    char true = 1;
    while(true) {
        struct AVLTree *x = a->parent;
        if(x == NULL) {
            break;
        }
        if(a == x->left) {
            x->balance--;
            if(!x->balance){
                break;
            }
            if(x->balance == -2) {
                if(a->balance == 1) {
                    t = RotateLeft(t, a);
                }
                t = RotateRight(t, x);
                break;
            }
        } else {
            x->balance++;
            if(!x->balance) {
                break;
            }
            if(x->balance == 2) {
                if(a->balance == -1) {
                    t = RotateRight(t, a);
                }
                t = RotateLeft(t, x);
                break;
            }
        }
        a = x;
    }
    return a;
}

char isDigit(char c) {
    return (c >= '0' && c <= '9');
}

char isSpec(char c) {
    char spec[6] = "+-*/()";
    for(int i = 0; i <= 5; i++)
        if(c == spec[i]) return i;
    return -1;
}

char isAlpha(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main(int argc, const char * argv[]) {
    
    struct AVLTree *tree;
    tree = InitBinarySearchTree(tree);
    
    int n;
    scanf("%d\n", &n);
    struct AVLTree *element = (struct AVLTree*)malloc(n * sizeof(struct AVLTree));
    
    char c;
    scanf("%c", &c);
    int i = 0;
    int j = 0;
    int value = 0;
    while(i < n) {
        if(isDigit(c)) {
            int digit = c - '0';
            int constant = digit;
            while(isDigit(c) && i < n) {
                scanf("%c", &c);
                i++;
                if (isDigit(c)) {
                    digit = c - '0';
                    constant = constant * 10 + digit;
                }
            }
            printf("CONST %d\n", constant);
            continue;
        } else if(isSpec(c) != -1) {
            printf("SPEC %d\n", isSpec(c));
            scanf("%c", &c);
            i++;
            continue;
        } if(isAlpha(c)){
            char id[100];
            int k = 0;
            while( (isAlpha(c) || isDigit(c) ) && i < n) {
                id[k] = c;
                scanf("%c", &c);
                i++;
                k++;
            }
            id[k] = '\0';
            struct AVLTree *elem = Descend(tree, id);
            if(elem == NULL) {
                element[j].k = (char*)malloc(100 * sizeof(char));
                strcpy(element[j].k, id);
                element[j].v = value;
                element[j].parent = NULL;
                element[j].left = NULL;
                element[j].right = NULL;
                element[j].balance = 0;
                tree = InsertAVL(tree, id, &element[j]);
                j++;
                printf("IDENT %d\n", value);
                value++;
            } else {
                printf("IDENT %d\n", elem->v);
            }
            continue;
        } else {
            scanf("%c", &c);
            i++;
        }
    }
    
    for(int i = 0; i <= j - 1; i++) {
        free(element[i].k);
    }
    free(element);
    
    return 0;
}
