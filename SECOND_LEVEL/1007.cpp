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
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
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
    int sum = - 1e+9;
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(sum < dp[i])
        {
            sum = dp[i];
            j = i;
        }
    }
    printf("%d %d %d", sum, num[re[j]], num[j]);
    system("pause");
    return 0;
}