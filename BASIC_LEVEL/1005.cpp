#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 110;
bool is[maxn] = {false};
int n, nums[maxn];

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    scanf("%d", &n);
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }
    for(int i = 0; i < n; i++)
    {
        int k = nums[i];
        if(is[k] != true && i != 0)
        {
            ans.push_back(k);
        }
        is[k] = true;
        while(k != 1)
        {
            if(k % 2 == 0)
            {
                k = k / 2;
                is[k] = true;
            }
            else
            {
                k = k * 3 + 1;
                is[k] = true;
            }
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for(auto it = ans.begin(); it != ans.end(); it++)
    {
        printf("%d", *it);
        if(it != ans.end() - 1)
        {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}