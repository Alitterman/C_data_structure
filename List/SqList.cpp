#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
#define ElemType int

//静态分配
typedef struct
{
    int data[MaxSize];
    int Length;
} SqList;

bool initList(SqList &L);
bool getElement(SqList L, int i, ElemType &e);
bool ListInsert(SqList &L, int i, ElemType &e);
bool ListDelete(SqList &L, int i, ElemType &e);
int locatList(SqList L,ElemType e);



int main()
{

    SqList L;
    int e = 10;
    int x, y;
    initList(L);
    //录入初始数据
    L.data[0] = 5;
    L.Length++;
    getchar();
    //在位置1处插入数据
    if (ListInsert(L, 1, e))
        printf("插入成功！值为:%d", e);
    else
        printf("插入失败！");

    //在位置2处删除数据
    ListDelete(L, 2, x);
    if (ListDelete(L, 1, e))
        printf("插入成功！值为:%d", e);
    else
        printf("删除失败！");

    return 0;
}

bool initList(SqList &L)
{
    //if(!L.data) exit(0);
    L.Length = 0;
    return true;
}
//插入操作
bool ListInsert(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.Length)
        return false;
    if (L.Length >= MaxSize)
        return false;
    for (int j = L.Length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.Length++;
    L.data[i - 1] = e;
    return true;
}
bool ListDelete(SqList &L, int i, ElemType &e)
{
    if (i < 1 || i > L.Length)
        return false;
    //返回删除的元素的值
    e = L.data[i - 1];
    for (int j = i; j < L.Length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.Length--;
    return true;
}
bool getElement(SqList L, int i, ElemType &e)
{
    if (i < 1 || i > L.Length)
        return false;
    e = L.data[i - 1];

    return true;
}
int locatList(SqList L,ElemType e){
    for(int i = 0; i<L.Length;i++){
        if(L.data[i]==e)
            return i+1;
    }
    //查找失败返回-1
    return -1;


}