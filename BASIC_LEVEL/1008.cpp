#include <cstdio>
#include <iostream>
#include <vector>

const int maxn = 100;
int n, m;
int nums[maxn];
using namespace std;

int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n;i++)
    {
        scanf("%d", &nums[i]);
    }
    m = m % n;
    for(int i = n - m; i < n; i++)
    {
        printf("%d", nums[i]);
        if(i != n-1)
        {
            printf(" ");
        }
    }
    if(n - m != 0)
    {
        printf(" ");
    }
    for(int i = 0; i < n - m; i++)
    {
        printf("%d", nums[i]);
        if(i != n - m - 1)
        {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}