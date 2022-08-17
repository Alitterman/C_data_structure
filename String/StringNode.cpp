#include <stdio.h>
#include <stdlib.h>

typedef struct StringNode
{
    char ch;
    struct StringNode *next;
}StringNode, *String;
//字符串用链表存储密度低，每个字符1B，每个指针4B

//可采用多个字符存储在一个空间优化
typedef struct MStringNode
{
    char ch[4];
    struct StringNode *next;
}MStringNode, *MString;