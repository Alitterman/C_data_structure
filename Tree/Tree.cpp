#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef struct TreeNode{
    int value[MaxSize];
    bool isEmpty;
}

//链式存储
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

bool initTree(BiTNode &root){
    root  = (BiTNode) malloc(sizeof(BiTNode));
    root.data = 1;
    root->lchild = NUll;
    root->rchild = NUll;

}


int main{
    BiTNode root;
    initTree(root);

}


