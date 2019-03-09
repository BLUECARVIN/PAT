#include <cstdio>
#include <iostream>

using namespace std;


int main()
{
    int num, k;
    scanf("%d %d", &num, &k);
    int t = 0, ans[40];
    if(num == 0)
    {
        ans[t++] = 0;
    }
    while(num != 0)
    {
        ans[t++] = num % k;
        num = num / k;
    }
    
    int i = 0, j = t - 1, flag = 1;
    while(i < j)
    {
        if (ans[i++] != ans[j--])
        {
            flag = 0;
            break;
        }
    }
    if(flag == 1)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }
    for(int i = t - 1; i >= 0 ; i--)
    {
        printf("%d", ans[i]);
        if(i != 0)
        {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}
