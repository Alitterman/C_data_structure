#include <stdio.h>
#include <stdlib.h>
using namespace std;

/*
输出函数
输入 整型 ans

输出 ans的汉语拼音 
*/

void printf2(int ans)
{
    int curnum;
    char *num[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "shi"};
    if (ans)
    {
        curnum = ans % 10;
        ans /= 10;
        printf2(ans);
        //当和的十位数不为零的时候，输出空格
        if (ans > 0)
        {
            printf(" ");
        }

        printf("%s", num[curnum]);
    }
}

/*
主程序
输入 整型 n

输出 整数n的各位数和的汉语拼音 
*/
int main()
{
    char n[110];
    int i = 0;
    long ans = 0;
    scanf("%s", &n);

    while (n[i])
    {
        // 得到整数n的第i位的数字并求和
        ans += n[i] - '0';
        i++;
    }
    printf2(ans);

    system("pause");

    return 0;
}