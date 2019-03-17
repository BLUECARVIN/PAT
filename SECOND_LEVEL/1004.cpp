#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int maxn = 110;
vector<int> Tree[maxn];
int n, m;


int main()
{
    int ans[101];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d %d", &a, &b);
        for(int j = 0; j < b; j++)
        {
            scanf("%d", &c);
            Tree[a].push_back(c);
        }
    }

    queue<int> q;
    int level = 0;
    int p;
    q.push(1);
    int len = q.size();
    int count = 0;
    while(!q.empty())
    {
        len --;
        if(len == 0)
        {
            p = q.front();
            q.pop();
            if(Tree[p].size() == 0)
            {
                count ++;
            }
            else
            {
                for(int i = 0; i < Tree[p].size(); i++)
                {
                    q.push(Tree[p][i]);
                }
            }
            len = q.size();
            ans[level++] = count;
            count = 0;
        }
        else
        {
            p = q.front();
            q.pop();
            if(Tree[p].size() == 0)
            {
                count ++;
            }
            else
            {
                for(int i = 0; i < Tree[p].size(); i++)
                {
                    q.push(Tree[p][i]);
                }
            }
        }
    }
    for(int i = 0; i < level; i++)
    {
        printf("%d", ans[i]);
        if(i != level - 1)
        {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}