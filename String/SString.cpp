#include <stdlib.h>
#include <stdio.h>

#define MaxSize 50

typedef struct
{

    char *ch;
    int length = 0;
} SString;

bool InitString(SString &T){
    if(&T == NULL) return false;

    T.ch = new char[MaxSize];
    if(T.ch == NULL) return false;

    T.length = 0;
    return true;
}

//赋值操作
bool StrAssign(SString &T, char *chars)
{   
    InitString(T);
    for (int i = 0; chars[i]; i++)
    {
        if (i >= MaxSize)
        {
            return false;
        }
        T.ch[i] = chars[i];
        T.length++;
    }
    return true;
}
//复制操作
bool StrCopy(SString &T, SString S)
{

    T.length = 0;

    for (int i = S.length - 1; i >= 0; i--)
    {
        T.ch[i] = S.ch[i];
        T.length++;
    }
    return true;
}
//求串长
int StrLength(SString S)
{
    return S.length;
}
//清空操作
bool ClearString(SString &S)
{
    S.length = 0;
    return true;
}
//销毁操作
bool DestroyString(SString &S)
{
    free(S.ch);
    return true;
}
//联接操作
bool Concat(SString &T, SString S1, SString S2)
{
    T = S1;
    T.length = S1.length + S2.length;
    if (T.length > MaxSize)
    {
        return false;
    }

    for (int i = S1.length; i <= T.length; i++)
    {
        T.ch[i] = S2.ch[i - S1.length];
    }
    return true;
}

bool SubString(SString &Sub, SString S, int pos, int len)
{
    if (pos + len > S.length)
    {
        return false;
    }
    Sub.length = len;
    for (int i = pos - 1; i < pos + len -1; i++)
    {
        Sub.ch[i - pos + 1] = S.ch[i];
    }
    return true;
}
/*
比较操作
相等 return 0
大于 return 1
小于 return -1
*/
int Compare(SString S,SString T){
    
    int i = 0;
    
    while(i <= S.length && i <= T.length) {
        // 遇到不同的字符时，比较其大小
        if(S.ch[i] != T.ch[i]) {
            return S.ch[i] - T.ch[i];
        }
        
        i++;
    }
    
    return S.length - T.length;

}

int main()
{
    SString T;
    SString S1, S2,Sub;
    StrAssign(S1, "str");
    StrAssign(S2, "abc");

    Concat(T, S1, S2);
    SubString(Sub,T,2,2);
    for (int i = 0; i < Sub.length; i++)
    {
        printf("%c", Sub.ch[i]);
    }
    system("pause");
    return 0;
}
