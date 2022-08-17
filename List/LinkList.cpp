#include<stdlib.h>
#include<stdio.h>

#define ElemType int

typedef struct LNode
{
    ElemType date;
    LNode *next;
}LNode,*LinkList ;

bool InitList(LinkList &L){
    L = new LNode;
    L->date = NULL;
    return true;
}

bool isEmpty(LinkList L)
{
    return (L == NULL);
}


bool insertList(LinkList &L,int i,ElemType e){
    if(i<1){
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while(p!= NULL && j < i -1)
    {
        p = p->next;
        j++;
    }
    //判断i值合法性
    if(p==NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->date =e;
    s->next = p->next;
    p->next =s;
    return true;
}


int main(){
    LinkList L;
    InitList(L);


    return 0;
}