#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
const int maxn = 110;
vector<int> Tree[maxn];
int ans[maxn];
int level = 1;

void Level_order(int s)
{
    queue<int> Q;
    int len;
    int p;
    Q.push(s);
    len = Q.size();
    while(!Q.empty())
    {
        len --;
        if(len == 0)
        {
            p = Q.front();
            for(int i = 0; i < Tree[p].size(); i++)
            {
                Q.push(Tree[p][i]);
            }
            Q.pop();
            ans[level++] = Q.size();
            len = Q.size();
        }
        else
        {
            p = Q.front();
            Q.pop();
            for(int i =0; i < Tree[p].size(); i++)
            {
                Q.push(Tree[p][i]);
            }
        }
    }
};
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int k, c, j;
        scanf("%d %d", &k, &c);
        for(int l = 0; l < c; l++)
        {
            scanf("%d", &j);
            Tree[k].push_back(j);
        }
    }
    Level_order(1);
    int sum = 0, j;
    for(int i = 1; i <= level; i++)
    {
        {
            if(sum < ans[i])
            {
                sum = ans[i];
                j = i;
            }
        }
    }
    printf("%d %d", sum, j+1);
    system("pause");
    return 0;
}

