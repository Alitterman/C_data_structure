#include<stdlib.h>
#include<stdio.h>


#define MaxSize 50


typedef struct {

    char *ch;
    int length;
}HString;

void InitString(HString &S){

    S.ch = (char *)malloc(MaxSize * sizeof(char));
    S.length = 0;

}


