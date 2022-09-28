#include <stdio.h>
#include<stdlib.h>
using namespace std;

int main(){

    int n,sum;
    scanf("%d",&n);
    sum = 0;

    while( n != 1){
        if( n%2 == 0){
            n /= 2;
            
        }else{
            n = (3 * n + 1)/2;
        }
        sum++;

    };
    printf("%d\n",sum);
    system("pause");
    return 0;
    
    
}