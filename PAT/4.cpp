#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;
/* 
 *大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！
 * 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。
 * 大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，
 * 因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，
 * 代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；
 * 后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。
*/
int main()
{

    char str1[60], str2[60], str3[60], str4[60];
    int flag = 0;
    char day[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    cin >> str1 >> str2 >> str3 >> str4;

    for (int i = 0; i < 60; i++)
    {
        if (str1[i] == str2[i] )
        {
            if (flag == 0 && str1[i] <= 'G' && str1[i] >= 'A')
            {
                cout << day[str1[i] - 'A'] << " ";
                flag++;
            }
            else if(flag !=0)
            {
                if (str1[i] <= '9' && str1[i] >= '0')
                {
                    cout << '0' << str1[i] - '0' << ":";
                    break;
                }
                else if (str1[i] <= 'N' && str1[i] >= 'A')
                {
                    cout << (str1[i] - 'A') + 10 << ":";
                    break;
                }
            }
        }
    }

    for (int i = 0; i < 60; i++)
    {
        if (str3[i] == str4[i])
        {
            if ((str3[i] <= 'Z' && str4[i] >= 'A') || (str3[i] <= 'z' && str3[i] >= 'a'))
            {
                if (i < 10)
                {
                    cout << '0' << i;
                    break;
                }
                else
                {
                    cout << i << endl;
                    break;
                }
            }
        }
    }

    system("pause");
    return 0;
}