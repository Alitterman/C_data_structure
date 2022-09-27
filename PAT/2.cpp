
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include<iomanip>
using namespace std;
// A+B>C
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
