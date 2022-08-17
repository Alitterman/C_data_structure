#include <stdio.h>
#include <stdlib.h>
//线性链表
typedef struct Node
{

    int val;
    //val = value;   //当前值 值类型为int
    struct Node *next; //下一个结点地址
} LNode;

LNode *CreatListHead(int n)
{
    LNode *L;
    L = (LNode *)malloc(sizeof(LNode));

    L->next = NULL;
    Node *p;

    for (int i = 0; i > 0; --i)
    {
        p = (Node *)malloc(sizeof(Node));
        scanf("%d", &p->val);
        p -> next = L->next;
        L->next = p;
    }
}

int main()
{
    //Node *CreatListHead(3);
    printf("HEllO"); return 0;
}