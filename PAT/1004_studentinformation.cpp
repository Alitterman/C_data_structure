#include <stdio.h>
#include <stdlib.h>

struct 
{
    char *name;
    char *s_num;
    int socre;
}a[100];


int main()
{
    int n;
    scanf("%d",&n);
   for(int i = 0;i<n;i++)
    {

        scanf("%s %s %d",&a[i].name,&a[i].s_num,&a[i].socre);
    }

    printf("%s %s %d",a[0].name,a[0].name,a[0].name);
}