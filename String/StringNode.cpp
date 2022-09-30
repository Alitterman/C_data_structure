#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

#define MAXSIZE 100

typedef struct StringNode
{
    char ch;
    struct StringNode *next;
}StringNode, *String;
//字符串用链表存储密度低，每个字符1B，每个指针4B

//可采用多个字符存储在一个空间优化
typedef struct MStringNode
{
    char ch[MAXSIZE+1];
    struct StringNode *next;
}MStringNode, *MString;