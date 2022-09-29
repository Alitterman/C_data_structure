#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define MAXSIZE 100
#define ElemType int
typedef struct Stack
{
    ElemType *top,*base;
    int stacksize;
}SqStack;

bool InitStack(SqStack &S);

bool DestroyStack(SqStack &S);

bool InitStack(SqStack &S){

    S.base = new int[MAXSIZE];
    if(S.base==NULL)
    {
        exit(0);
    }
    //初始栈顶指向栈底
    S.top =S.base;
    S.stacksize = MAXSIZE;
    return true;
}

bool DestroyStack(SqStack &S){
    if(&S == NULL){
        exit(0);
    }

    free(S.base);
    S.base=NULL;
    S.top=NULL;
    S.stacksize=0;
    
    return true;
}


bool Push(SqStack &S,ElemType e){

    if(&S==NULL||S.base==NULL){
        exit(0);
    }

    if(S.top-S.base>=S.stacksize){
        S.base = (ElemType*)realloc(S.base,(S.stacksize+10)*sizeof(ElemType));
        if(S.base==NULL){
            exit(0);
        }

        //S.top 指向以前分配的那块内存，所以要重定向一下指向之前栈顶的位置
        S.top = S.base + S.stacksize;
        S.stacksize += 10;

    }

    // 进栈先赋值，栈顶指针再自增
    *(S.top++) = e;

    return true;

    

}

bool Pop(SqStack &S,ElemType &e){
    if(&S==NULL||S.base==NULL){
        exit(0);
    }

    if(S.top==S.base){
        return false;//栈空
    }

    e = *(--S.top);
    return true;
}


int main(){

    SqStack S;
    InitStack(S);
    int num,x;
    int e;
    
    cout <<  "请输入一个10进制数\n";
    cin  >> num;
    while(num>0){
        Push(S,num%8); 
        num /=8;
        
    }

    while(S.top!=S.base){
        Pop(S,e);
        printf("%d",e);
    }
    cout<<endl;

    system("pause");
    return 0;
}

 