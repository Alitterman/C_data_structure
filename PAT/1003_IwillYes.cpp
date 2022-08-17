#include <stdio.h>
#include <stdlib.h>
#include <cstring>

int main()
{
    int n;
    scanf("%d", &n);

    while (n--)
    {
        char arr[101] = {0};
        scanf("%s", &arr);
        int len = strlen(arr);
        int i = 0, p = 0, t = 0, left = 0, mid = 0, right = 0;

        //判断字符串每段字符个数
        for (int i = 0; i < len; i++)
        {
            if (arr[i] == 'A' && p == 0 && t == 0)
            {
                left++;
            }
            else if (arr[i] == 'P' && p == 0 && t == 0)
            {
                p++;
            }
            else if (arr[i] == 'A' && p == 1 && t == 0)
            {
                mid++;
            }
            else if (arr[i] == 'T' && p == 1 && t == 0)
            {
                t++;
            }
            else if (arr[i] == 'A' && p == 1 && t == 1)
            {
                right++;
            }
            else
            {
                break;
            }
        }
        //根据条件判断是否符合要求
        if (p == 1 && t == 1 && mid == 1 && left == right){
            printf("Yes\n");            
        }else if (p == 1 && t == 1 && mid>0 && right == left*mid){
            printf("Yes\n");            
        }else {
            printf("No\n");            
        }
    }

    system("pause");
    return 0;
}