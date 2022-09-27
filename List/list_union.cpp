#include<iostream>
#include "stdlib.h"
#include "Seq_List.h"
using namespace std;

void merge_list(List LA,List LB,List &LC){
    
    int pA=0,pB=0;
    int pC=1;
    while (true){
        if(LA.elem[pA]<LB.elem[pB]){
            InsertElem(LC,pC++,LA.elem[pA++]);
            if(pA>LA.lenght-1){
                for(int j = pB;j < LB.lenght;j++){
                    InsertElem(LC,pC++,LB.elem[j]);
                }
                break;
            }
        }
        else{
            InsertElem(LC,pC++,LB.elem[pB++]);
            if(pB>LB.lenght-1){
                for(int j = pA;j < LA.lenght;j++){
                    InsertElem(LC,pC++,LA.elem[j]);
                }
                break;
            }
        }

    }
    printf("OK\n");

}



int main(){
    List LA,LB;
    List LC;
    InitList(LC);
    InitList(LA);
    InitList(LB);
    int a1[100] = {3,5,8,11};
    int a2[100] = {2,6,8,9,11,15,20};
    LA.elem = &a1[0];
    LA.lenght = 4;
    LB.elem = &a2[0];
    LB.lenght = 7;
    merge_list(LA,LB,LC);
    //输出数组中所有的元素
    printf("Listlenght: %d, List values is:\n", LC.lenght);
    for (int i = 0; i < LC.lenght; i++)
    {
        printf("%d\n", LC.elem[i]);
    }


    system("pause");






    return 0;
}