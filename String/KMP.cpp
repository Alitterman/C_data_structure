#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef unsigned char SString[100 + 1];

int Violence(SString T1, SString T2)
{
    int i = 1, j = 1;

    while (T1[i] != '\0')
    {
        if (T1[i] == T2[j])
        {
            i++;
            if (T2[++j] == '\0')
            {
                return i - T2[0];
            }
        }
        else
        {
            i = i - j + 2; //指针后退重新开始匹配
            j = 1;
        }
    }
    return -1;
}

int KMP(SString T1, SString T2, int next[])
{
    int i = 1, j = 1;

    while (i <= T1[0] && j <= T2[0])
    {
        if (j == 0 || T1[i] == T2[j])
        {
            i++;
            if (T2[++j] == '\0')
            {
                return i - T2[0];
            }
        }
        else
        {
            // i = i - j + 2;//指针后退重新开始匹配
            j = next[j];
        }
    }
    return -1;
}

int StrAssign(SString T, const char *chars)
{
    int i, len;

    len = (int)strlen(chars);

    // chars过长
    if (len > 100)
    {
        return -1;
    }

    T[0] = len;
    for (i = 1; i <= len; i++)
    {
        T[i] = chars[i - 1];
    }
    T[len + 1] = '\0';

    return 1;
}

void get_next(SString T, int next[])
{
    int i = 1;
    int j = 0;

    // 模式串第一个字符处失配时，模式串需要从头比较，主串需要前进到下一个位置比较
    next[1] = 0;

    // 遍历模式串上的字符
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            i++;

            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}
void get_nextval(SString T, int next[])
{
    int i = 1;
    int j = 0;
    while (i < T[0])
    {
        if (j == 0 || T[i] == T[j])
        {
            i++;
            j++;
            if (T[i] != T[j])
            {
                cout << "T["<<i <<"]("<< T[i]<<") != " << "T[" <<j<<"]("<< T[j]<<")" <<"  next["<<i <<"]="<<j<<endl;
                next[i] = j;
            }
            else
            {
                cout << "T["<<i <<"]("<< T[i]<<") == " << "T[" <<j<<"]("<< T[j]<<")" <<"  next["<<i <<"]="<<"next["<<j <<"]"<<endl;
                next[i] = next[j];
            }
        }
        else
        {
            cout << "j = next[j]("<<next[j]<<")" <<endl;
            j = next[j];
            
        }
    }
}

int main()
{
    SString s1, s2;

    StrAssign(s1, "abaaaaaaaaabacc");
    StrAssign(s2, "abcbcbabcaa");
    cout << "S  =" << Violence(s1, s2) << endl;

    int next[s2[0] + 1];
    cout << next[0] << endl;

    get_next(s2, next);
    printf("next    : ");
    for (int i = 1; i <= s2[0]; i++)
    {
        printf("%d", next[i]);
    }
    printf("\n");
    get_nextval(s2, next);
    printf("next    : ");
    for (int i = 1; i <= s2[0]; i++)
    {
        printf("%d", next[i]);
    }
    printf("\n");

    cout << "S  =" << KMP(s1, s2, next) << endl;

    system("pause");
}
