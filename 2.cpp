
#include <stdlib.h>
#include<stdio.h>

int main()
{
    int n;
    char x = '6';

    n = (long)x - '0';

    while(--n)
    {
        printf("%d\n", n);
        
    }

    system("pause");

    return 0;
}