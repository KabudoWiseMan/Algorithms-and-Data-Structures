//
//  ranktree.c
//  (10)Ranktree
//
//  Created by Vsevolod Molchanov on 27.01.17.
//  Copyright © 2017 Vsevolod Molchanov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

struct BinaryTree {
    int k, count;
    char *v;
    struct BinaryTree *parent;
    struct BinaryTree *left, *right;
};

struct BinaryTree* InitBinarySearchTree(struct BinaryTree *t) {
    t = NULL;
    return t;
}

struct BinaryTree* Minimum(struct BinaryTree *t) {
    struct BinaryTree *x;
    if(t == NULL) {
        x = NULL;
    }else{
        x = t;
        while(x->left != NULL) {
            x->count--;
            x = x->left;
        }
    }
    return x;
}

struct BinaryTree* Succ(struct BinaryTree *x) {
    struct BinaryTree *y;
    if(x->right != NULL) {
        y = Minimum(x->right);
    }else{
        y = x->parent;
        while(y != NULL && x == y->right) {
            x = y;
            y = y->parent;
        }
    }
    return y;
}

struct BinaryTree* Descend(struct BinaryTree *t, int k) {
    struct BinaryTree *x = t;
    while(x != NULL && x->k != k) {
        if(k < x->k) {
            x->count--;
            x = x->left;
        }else{
            x->count--;
            x = x->right;
        }
    }
    return x;
}

char* Lookup(struct BinaryTree *t, int k) {
    struct BinaryTree *x = Descend(t, k);
    if (x == NULL) {
        printf("panic\n");
        exit(1);
    }
    char *v = x->v;
    return v;
}

struct BinaryTree* Insert(struct BinaryTree *t, int k, struct BinaryTree *y) {
    if(t == NULL) {
        t = y;
    }else{
        struct BinaryTree *x = t;
        int true = 1;
        while(true) {
            if (x->k == k) {
                printf("panic\n");
                exit(1);
            }
            if(k < x->k) {
                if(x->left == NULL) {
                    x->count++;
                    x->left = y;
                    y->parent = x;
                    break;
                }
                x->count++;
                x = x->left;
            }else{
                if(x->right == NULL) {
                    x->count++;
                    x->right = y;
                    y->parent = x;
                    break;
                }
                x->count++;
                x = x->right;
            }
        }
    }
    return t;
}

struct BinaryTree* ReplaceNode(struct BinaryTree *t, struct BinaryTree *x, struct BinaryTree *y) {
    if(x == t) {
        t = y;
    }else{
        struct BinaryTree *p = x->parent;
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

struct BinaryTree* Delete(struct BinaryTree *t, int k) {
    struct BinaryTree *x = Descend(t, k);
    if (x == NULL) {
        printf("panic\n");
        exit(1);
    }
    if(x->left == NULL && x->right == NULL) {
        t = ReplaceNode(t, x, NULL);
    }else{
        if(x->left == NULL) {
            t = ReplaceNode(t, x, x->right);
        }else{
            if(x->right == NULL) {
                t = ReplaceNode(t, x, x->left);
            }else{
                struct BinaryTree *y = Succ(x);
                t = ReplaceNode(t, y, y->right);
                x->left->parent = y;
                y->left = x->left;
                if(x->right != NULL) {
                    x->right->parent = y;
                }
                y->right = x->right;
                t = ReplaceNode(t, x, y);
                y->count = x->count - 1;
            }
        }
    }
    
    return t;
}

struct BinaryTree* Search(struct BinaryTree *t, int x) {
    struct BinaryTree *y = Minimum(t);
    int counter = 0;
    while(counter != x) {
        y = Succ(y);
        counter++;
    }
    return y;
}

int main(int argc, const char * argv[]) {
    
    int n;
    scanf("%d", &n);
    
    struct BinaryTree *tree;
    tree = InitBinarySearchTree(tree);
    
    char *s = (char*)malloc(10 * sizeof(char));
    struct BinaryTree *element = (struct BinaryTree*)malloc(n * sizeof(struct BinaryTree));
    int j = 0;
    for(int i = 0; i <= n - 1; i++) {
        scanf("%s", s);
        if(!strcmp(s, "INSERT")) {
            char v[10];
            int k;
            scanf("%d %s", &k, v);
            element[j].k = k;
            element[j].v = (char*)malloc(10 * sizeof(char));
            strcpy(element[j].v, v);
            element[j].count = 0;
            element[j].parent = NULL;
            element[j].left = NULL;
            element[j].right = NULL;
            tree = Insert(tree, k, &element[j]);
            j++;
        }
        if(!strcmp(s, "LOOKUP")) {
            int k;
            scanf("%d", &k);
            printf("%s\n", Lookup(tree, k));
        }
        if(!strcmp(s, "DELETE")) {
            int k;
            scanf("%d", &k);
            tree = Delete(tree, k);
        }
        if(!strcmp(s, "SEARCH")) {
            int x;
            scanf("%d", &x);
            printf("%s\n", Search(tree, x)->v);
        }
    }
    
    for(int i = 0; i <= j - 1; i++) {
        free(element[i].v);
    }
    free(element);
    free(s);
    
    return 0;
}
