#include <iostream>
#include <stdlib.h>
using namespace std;
#define ElemType int

typedef struct LNode
{
    ElemType date;

    struct LNode *next;
} LNode, *LinkList;

bool InitList(LinkList *L); //初始化

bool DestroyList(LinkList *L); //销毁表

bool ClearList(LinkList L); //置空(内容)

bool ListEmpty(LinkList L); //判空

bool ListLength(LinkList L); // 计数

bool GetElem(LinkList L, bool i, ElemType *e); // 取值

bool LocateElem(LinkList L, ElemType e, bool(Compare)(ElemType, ElemType)); // 查找

bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e); // 前驱

bool NextElem(LinkList L, ElemType cur_e, ElemType *next_e); // 后继

bool ListInsert(LinkList L, bool i, ElemType e); // 插入

bool ListDelete(LinkList L, bool i, ElemType *e); // 删除

void ListTraverse(LinkList L, void(Visit)(ElemType)); // 遍历

bool CreateList_Head(LinkList *L, bool n, char *path); // 头插法创建链表

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
        L->date = NULL;
        L = p;
    }

    return true;
}

bool isEmpty(LinkList L)
{
    return (L == NULL);
}

bool insertList(LinkList &L, int i, ElemType e)
{
    if (i < 1)
    {
        return false;
    }
    LNode *p;
    int j = 0;
    p = L;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    //判断i值合法性
    if (p == NULL)
    {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->date = e;
    s->next = p->next;
    p->next = s;
    return true;
}

int main()
{
    LinkList L;
    InitList(L);

    return 0;
}
// #endif