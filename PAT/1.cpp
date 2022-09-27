#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
//A+B>C
int main()
{
    long long x, y, z;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y >> z;
        if(x+y>z){
            cout << "Case #"<< i+1 << ": true"<<endl;
        }
        else{
            cout << "Case #"<< i+1 << ": false"<<endl;
        }
    }
}
