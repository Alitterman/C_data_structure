#include<stdio.h>
#include<stdlib.h>

#define InitSize 10
#define ElemType int


int overflow=0;
//动态分配
typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
}SeqList;

void InitList(SeqList &L){
    //malloc函数申请连续的存储空间
    L.data = (ElemType *)malloc(InitSize*sizeof(ElemType));
    L.length = 0;
    L.MaxSize = InitSize;
}
//增加动态数组的长度
void IncreaseSize(SeqList &L,int len){
    // int *p = L.data;
    // L.data = (ElemType *)malloc((L.MaxSize+len)*sizeof(ElemType));
    // for (int i=0; i<L.length;i++){
    //     L.data[i] = p[i];
    // }
    L.data = (ElemType*) realloc(L.data,(L.MaxSize+len)*sizeof(ElemType));
    L.MaxSize += len;
}

int main(){
    SeqList L;
    InitList(L);
    printf("%d,%d\n",L.MaxSize,L.data);

    IncreaseSize(L,200);

    printf("%d,%d\n",L.MaxSize,L.data);
    system("pause");
    return 0;
}
