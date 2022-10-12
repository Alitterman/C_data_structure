#include <iostream>
#include "windows.h"
#include <stdlib.h>
using namespace std;
#define ElemType int

typedef struct LNode
{
    ElemType data;

    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList *L); //初始化

bool DestroyList(LinkList *L); //销毁表

bool ClearList(LinkList L); //置空(内容)

bool ListEmpty(LinkList L); //判空

int ListLength(LinkList L); // 计数

bool GetElem(LinkList L, int i, ElemType *e); // 取值

bool LocateElem(LinkList L, ElemType e, int(Compare)(ElemType, ElemType)); // 查找

bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e); // 前驱

bool NextElem(LinkList L, ElemType cur_e, ElemType *next_e); // 后继

bool ListInsert(LinkList L, int i, ElemType e); // 插入

bool ListDelete(LinkList L, int i, ElemType *e); // 删除

void ListTraverse(LinkList L, void(Visit)(ElemType)); // 遍历

bool CreateList_Head(LinkList *L, int n, char *path); // 头插法创建链表


int CreateList_Tail(LinkList *L, int n, char *path); // 尾插法创建链表

bool InitList(LinkList &L)
{
    L = new LNode;

    if (L == NULL)
    {
        exit(0); //内存分配失败，堆栈溢出
    }
    L->next = NULL;
    return true;
}

bool DestroyList(LinkList &L)
{
    LinkList p;
    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return false;
    }

    p = L;

    while (p != NULL) //遍历所有节点，释放内存
    {
        p = L->next;
        free(L);
        L = p;
    }

    L = NULL;

    free(p);
    p=NULL;
    return true;
}

bool ClearList(LinkList L)
{   //释放链表中非头结点处的空间
    LinkList p;
    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return false;
    }

    p = L->next;

    while (p != NULL) //遍历节点，将数据置空
    {
        p = L->next;
        free(L);
        L = p;
    }

    return true;
}

bool ListEmpty(LinkList L){
    return (L != NULL && L->next == NULL);
}

int ListLength(LinkList L){
    int lenght=0;

    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return -1;
    }


    L=L->next;//指向第一个节点
    
    while(L !=NULL){
        lenght++;
        L=L->next;
        
    }
    return lenght;
}

bool GetElem(LinkList L, int i, ElemType &e){
    int index = 0;
    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return false;
    }
    if(L->next==NULL){
        return false;//空表
    }

    

    while (index < i && L->next!=NULL)
    {   
        index++;
        L=L->next;
    }
    //遍历结束还找不到
    if(L == NULL || index > i) {
        return false;
    }

    e = L->data;

    return true;

}

bool isEmpty(LinkList L)
{
    return (L == NULL);
}

bool insertList(LinkList &L, int i, ElemType e)
{
    int index = 0;
    LinkList p;

    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return -1;
    }

    if (i < 1)
    {
        return false;
    }

    p = L;

    while (p != NULL && index < i-1)
    {
        index++;
        p = p->next;
        
    }
    if (p == NULL || index > i - 1)
    {
        return false;
    }
    //生成新节点
    LinkList s = (LinkList )malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next; 
    p->next = s;
    return true;
}

int find_k(LinkList L,int K,int &x)
{
    int length;
    LinkList p;
    if (&L == NULL || L == NULL) //确保链表结构存在
    {
        return -1;
    }

    if (K < 1)
    {
        return false;
    }

    length = ListLength(L);
    length = length-K;
    
    p = L->next;
    while(p!=NULL && length>0){
        length--;
        p = p->next;
    }

    x = p->data;

    return 0;



}
int main()
{
    LinkList L;
    int x;
    InitList(L);
    for(int i = 1; i < 10;i++){
        insertList(L,i,i*10);
    }
    for(int i = 1; i < 10;i++){
        GetElem(L,i,x);
        cout << x<<endl;
    }
    for(int i =1;i<10;i++){
        find_k(L,i,x);
        cout << x<<endl;
    }
    
    
    system("pause");


     return 0;
}
// #endif