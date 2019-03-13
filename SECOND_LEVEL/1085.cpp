#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 100010;
int n, p, a[maxn];

int upper_bound(int L, int R, int x)
{
    int left = L, right = R;
    while(left < right)
    {
        int mid = (left + right) / 2;
        if (a[mid] > x)
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    scanf("%d%d", &n, &p);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a, a+n); //递增排序
    int ans = 1; //记录最大长度， 初始值为1
    for(int i = 0; i < n; i++) //在a[i+1] - a[n-1]中查找第一个超过a[i]*p的数，返回位置给j
    {
        int j = upper_bound(a + i + 1, a+n, (long long)a[i] * p) - a;
        ans = max(ans, j - 1);
    }
    printf("%d\n", ans);
    system("pause");
    return 0;
}