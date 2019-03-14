#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn= 10010;
int dp[maxn], re[maxn] = {0} , num[maxn];

int main()
{
    int n;
    scanf("%d", &n);
    bool flag = false;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if(num[i] >= 0) flag = true;
    }
    if(flag == false) //若输入元素都为负数，则输出0以及首尾元素
    {
        printf("0 %d %d\n", num[0], num[n-1]);
    }
    dp[0] = num[0];
    re[0] = 0;
    for(int i = 1; i < n; i++)
    {
        dp[i] = max(num[i], dp[i - 1] + num[i]);
        if(num[i] < dp[i - 1] + num[i])
        {
            re[i] = re[i - 1];
        }
        else
        {
            re[i] = i;
        }
    }
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(dp[i] > dp[j])
        {
            j = i;
        }
    }
    printf("%d %d %d", dp[j], num[re[j]], num[j]);
    system("pause");
    return 0;
}