#include <stdio.h>
#include <stdlib.h>     // 提供malloc、realloc、free、exit原型
#include <iostream>
using namespace std;

#define ElemType int

typedef struct QNode{

    ElemType elem;
    struct QNode* next;

}QNode,*Queueptr;

typedef struct {
    Queueptr front;
    Queueptr rear;
}LinkQueue;



bool InitQueue(LinkQueue &Q);

bool DestroyQueue(LinkQueue &Q);
bool GetHead(LinkQueue Q, ElemType &e);
bool EnQueue(LinkQueue &Q, ElemType e);
bool DeQueue(LinkQueue &Q, ElemType &e);

//这里的队列带有头结点
bool InitQueue(LinkQueue &Q){
    if(&Q == NULL) {
        return false;
    }

    Q.front = new QNode;
    if(Q.front == NULL) {
    
        exit(0);
    }

    Q.rear = Q.front;

    Q.front->next = NULL;
    return true;

}
bool DestroyQueue(LinkQueue &Q){

    if(&Q==NULL){
        return false;
    }
    
    while(Q.front){
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front= Q.rear;
    }

}

bool GetHead(LinkQueue Q, ElemType &e){

    if(&Q == NULL || Q.front == Q.rear) {
        return false;
    }

    e = Q.front->next->elem;

    return true;
}


bool EnQueue(LinkQueue &Q, ElemType e){
    Queueptr p;

    if(&Q == NULL||Q.front == NULL){
        return false;
    }

    p = new QNode;
    if(!p){
        exit(0);
    }

    p->elem = e;
    p->next = NULL;

    Q.rear->next = p;
    Q.rear = p;
}

bool DeQueue(LinkQueue &Q, ElemType &e){
    Queueptr p;
    if(&Q == NULL||Q.front == NULL){
        return false;
    }
    if(Q.front == Q.rear){
        return false;
    }
    p = Q.front->next;

    e = p->elem;

    Q.front->next = p->next;
    if(Q.rear==p){
        Q.rear=Q.front;
    }

    free(p);
    return true;




}