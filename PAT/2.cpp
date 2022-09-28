
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<iomanip>
using namespace std;
/* 给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：
*  A1 = 能被5整除的数字中所有偶数的和；
* 
*  A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
*
*  A3 = 被5除后余2的数字的个数；
* 
*  A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
* 
*  A5 = 被5除后余4的数字中最大数字。
*/
int main()
{
    int x;
    int n;
    int flag = 0, sum = 0;
    long A1 = 0, A2 = 0, A3 = 0, A5 = 0;
    float A4 = 0;


    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 5 == 0 && x % 2 == 0)
        {
            A1 += x;
        }
        else if (x % 5 == 1)
        {
            if (flag == 0)
            {
                A2 += x;
                flag =1;
            }
            else
            {
                A2 -= x;
                 flag =0;
            }
        }
        else if (x % 5 == 2)
        {
            A3++;
        }
        else if (x % 5 == 3)
        {
            A4+=(float)x;
            sum++;
        }
        else if(x % 5 == 4)
        {
            if(A5<x){
                A5 = x;
            }
        }
    }



    if(A1!=0){
        cout << A1<<" " ;
    }
    else{
        cout <<"N ";
    }
    if(A2!=0){
        cout << A2<<" " ;
    }else{
        cout <<"N ";
    }
    if(A3!=0){
        cout << A3<<" " ;
    }else{
        cout <<"N ";
    }
    if(A4!=0){
        cout << setiosflags(ios::fixed) << setprecision(1)<<  A4/sum<<" " ;
    }else{
        cout <<"N ";
    }
    if(A5!=0){
        cout << A5<<endl;
    }else{
        cout <<"N "<<endl;
    }
    


    system("pause");


}
