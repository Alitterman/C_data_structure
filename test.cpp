#include <iostream>
#include "stdlib.h"
#include "stdio.h"




void test_1(){
    int *p;

    int a1[100] = {3,5,8,11};
    int a2[100] = {2,6,8,9,11,15,20};
    p = &a2[0];
    printf("sizeof(a) = %d\n", sizeof(a1));

    for(int i=0;i<10;i++){
        printf("%d\n",p[i]);
    }



}

void print_int(int num){
    printf("%d\n",num);
}
void print_int_ptr(int *num){
    
    printf("ptr: %p  num:%d\n",num,*num);
}

void test_2(){
    int *p;
    int *q = (int*)malloc(sizeof(int));
    int x=10;
    
    p = &x;
    *q = 10;
    // q = p;
    print_int(x);
    print_int_ptr(&x);
    print_int_ptr(p);
    print_int_ptr(q);
    free(q);//free 操作本身是将q所占的内存的使用权交换给操作系统，并没有把指针本身给销毁掉，这个指针本身还指向这块地址，为了防止对q进行的读写操作(主要是write)造成的undefined错误，建议与q==NULL搭配进行原子化操作
    print_int(x);
    print_int_ptr(p);
    print_int_ptr(q);//释放q内存后，地址内空间归操作系统管理，其指向的值随时可能会发生改变，其也会变为一个悬空指针
    // *q=10; // free后的指针写操作是非常危险的事情，ree(即运行库)会将这块内存标记为未使用，下次有可能会将这块内存分配出去。严重情况可能导致系统崩溃，
    // printf("ptr: %d\n",*q);

    q=NULL;//地址值指向000000000000（系统保留的不可访问地址)
    
    printf("ptr: %p\n",q);


}



int main(){

    test_2();

    system("pause");

    return 0;
}