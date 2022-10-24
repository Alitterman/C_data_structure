#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
using namespace std;



typedef struct TreeNode{
    int data;
    int height;
    TreeNode *leftchild, *rightchild;
}*Tree;


// Tree SingleRotate_LL(Tree &T);
// Tree DoubleRotate_LR(Tree &T);
// Tree SingleRotate_RR(Tree &T);
// Tree DoubleRotate_RL(Tree &T);

int InitBiTree(Tree &T){
    if (T==NULL) return 0;

    T = new TreeNode;

    //初始化
    T->data = NULL;
    T->height = 1;
    T->leftchild = NULL;
    T->rightchild = NULL;


    return 1;

}


int createTree(Tree &T,int data[],int length){
    
    if(T==NULL) return 0;
    //根节点赋值
    T->data = data[0];
    
    for(int i=1;i < length;i++){
        T =  insert(data[i],T,T->height); 
        
    }
    
}

Tree insert(int x,Tree &T,int height){
    int leftchild_height,rightchild_height;

    if(T==NULL){
        T = new TreeNode;

        T->data = x;
        T->height = height+1;
        T->leftchild = NULL;
        T->rightchild = NULL;

    }
    else if(x < T->data){

        T->leftchild = insert(x,T->leftchild,T->height);

        //计算左右子树层高
        leftchild_height = T->leftchild->height;
        rightchild_height =   T->rightchild !=NULL ? T->rightchild->height:T->height;

        //计算平衡因子，平衡因子等于2则失衡
        if(leftchild_height - rightchild_height == 2){
            if(x>(T->leftchild->data))
                T=SingleRotate_LL(T);
            else
                T=DoubleRotate_LR(T);
        }
    }else if(x > T->data){

        T->rightchild = insert(x,T->rightchild,T->height);

        //计算左右子树层高
        leftchild_height = T->leftchild->height;
        rightchild_height =   T->rightchild !=NULL ? T->rightchild->height:T->height;

        //计算平衡因子，平衡因子等于2则失衡
        if(rightchild_height - leftchild_height == 2){
            if(x>(T->rightchild->data))
                T=SingleRotate_RR(T);
            else
                T=DoubleRotate_RL(T);
        }
    }
    T->height=max(leftchild_height,leftchild_height)+1;
    return T;
}

//LL类型的单向旋转
Tree SingleRotate_LL(Tree &p2)
{
    Tree p1 = new TreeNode;
    p1=p2->leftchild;
    p2->leftchild=p1->rightchild;
    p1->rightchild=p2;
    while(!p2->rightchild){
        p2->height -= 1;
        p2=p2->rightchild;
    }
    while(!p1->leftchild){
    p1->height+=1;
    p1=p1->leftchild;
    }
    return p1;
}
//RR类型的单向旋转
Tree SingleRotate_RR(Tree &p2)
{
    Tree p1;
    p1=p2->rightchild;
    p2->rightchild=p1->leftchild;
    p1->leftchild=p2;

    return p1;
}
//LR类型的双向旋转
Tree DoubleRotate_LR(Tree p)
{
    p->leftchild=SingleRotate_RR(p->leftchild);
    return SingleRotate_LL(p);
}
//RL类型的双向旋转
Tree DoubleRotate_RL(Tree p)
{
    p->rightchild=SingleRotate_LL(p->rightchild);
    return SingleRotate_RR(p);
}