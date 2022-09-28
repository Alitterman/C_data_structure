#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
using namespace std;

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