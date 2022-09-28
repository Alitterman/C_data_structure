#include<stdio.h>
#include<stdlib.h>

#define MaxSize 100

typedef struct TreeNode{
    int value[MaxSize];
    bool isEmpty;
};

//链式存储
typedef struct BiTNode{
    int data;
    struct BiTNode *lchild, *rchild;
}BiTNode,*BiTree;

bool initTree(BiTree &root);


bool initTree(BiTree &root){
    root = new BiTNode;
    root->data = 1;
    root->lchild = NULL;
    root->rchild = NULL;

};


int main()
{
    BiTree root;
    initTree(root);
    return 0;
};


