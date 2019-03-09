#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    map<int, double> ans;
    int k;
    int n1;
    double n2;
    scanf("%d", &k);
    for(int i = 0; i < k; i++)
    {
        scanf("%d %lf", &n1, &n2);
        ans[n1] = n2;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i ++)
    {
        scanf("%d %lf", &n1, &n2);
        if(ans.find(n1) != ans.end())
        {
            ans[n1] += n2;
        }
        else
        {
            ans[n1] = n2;
        }
    }
    vector<int> a;
    for(map<int, double>::iterator it = ans.begin(); it != ans.end(); it ++)
    {
        if (it->second != 0.0)
        {
            a.push_back(it->first);
        }
    }
    printf("%d", a.size());
    sort(a.begin(), a.end());
    for(int i = a.size() - 1; i >= 0; i--)
    {
        printf(" %d %.1lf", a[i], ans[a[i]]);
    }
    system("pause");
    return 0;
}