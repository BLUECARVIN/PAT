#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
const int maxn = 1010;
bool visited[maxn] = {false};
vector<int> G[maxn];
int currentPoint; //记录当前要删除的结点

void DFS(int s)
{
    if (s == currentPoint)
    {
        return;
    }    
    visited[s] = true;
    for(int i = 0; i < G[s].size(); i++)
    {
        if(visited[G[s][i]] == false)
        {
            DFS(G[s][i]);
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(1);
    }
    for(int i = 0; i < k; i++)
    {
        scanf("%d", &currentPoint);
        memset(visited, false, sizeof(visited));
        int block = 0; //连通块个数
        for(int j = 1; j <= n; j++)
        {
            if(j != currentPoint && visited[j] == false)
            {
                DFS(j);
                block++;
            }
        }
        printf("%d\n", block -1);
    }
    system("pause");
    return 0;
}