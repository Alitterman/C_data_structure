#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <iostream>
using namespace std;

#define ElemType int
#define MAXSIZE 100

typedef struct SqQueue{

    ElemType *base;
    int front,rear;

}SqQueue;

bool InitQueue(SqQueue &Q);

bool DestroyQueue(SqQueue &Q);
bool GetHead(SqQueue Q, ElemType &e);
bool EnQueue(SqQueue &Q, ElemType e);
bool DeQueue(SqQueue &Q, ElemType &e);


bool InitQueue(SqQueue &Q){

    if(&Q==NULL)return false;

    Q.base = (ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
    if(Q.base==NULL)return false;

    Q.front = 0;
    
    Q.rear = Q.front;
    return true;
}


bool GetHead(SqQueue Q, ElemType &e){
    
    if(&Q==NULL)return false;
    if(Q.front==Q.rear)return false;

    e = Q.base[Q.front];


    return true;
}

bool EnQueue(SqQueue &Q, ElemType e){
    if(&Q==NULL)return false;

    if((Q.rear+1)%MAXSIZE == Q.front)return false;
    
    Q.base[Q.rear] = e;

    Q.rear = ++Q.rear % MAXSIZE;

    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e){

    if(&Q==NULL)return false;

    if(Q.front ==Q.rear)return false;

    e = Q.base[Q.front];

    Q.front = ++Q.front % MAXSIZE;


    return true;
}


int main(){
    SqQueue S;
    int e=0;
    InitQueue(S);
    EnQueue(S,1);
    EnQueue(S,2);
    EnQueue(S,3);
    EnQueue(S,4);
    EnQueue(S,5);
    
    DeQueue(S,e);
    cout << e << ends;
    DeQueue(S,e);
    cout << e << ends;
    DeQueue(S,e);
    cout << e << ends;
    DeQueue(S,e);
    cout << e << ends;
    DeQueue(S,e);
    cout << e << ends;


    system("pause");
    return 0;

}