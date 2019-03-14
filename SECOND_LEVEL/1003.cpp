#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
//num[i]表示从出发点到i结点最短路径的条数， w[i]表示从出发点到i点救援队的数目之和
bool visited[510];
const int INF = 1e+9;

int main()
{
    scanf("%d %d %d %d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    fill(e[0], e[0] + 510*510, INF);
    fill(dis, dis+510, INF);
    int a, b, c;
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        e[a][b] = e[b][a] = c;
    }
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    for(int i = 0; i < n; i++)
    {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++)
        {
            if(visited[j] == false && dis[j] < min)
            {
                u = j;
                min = dis[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == false && e[u][v] != INF)
            {
                if(dis[u] + e[u][v] < dis[v])
                {
                    dis[v] = dis[u] + e[u][v];
                    num[v] = num[u];
                    w[v] = w[u] + weight[v];
                }
                else if(dis[u] + e[u][v] == dis[v])
                {
                    num[v] = num[v] + num[u];
                    if(w[u] + weight[v] > w[v])
                    {
                        w[v] = w[u] + weight[v];
                    }
                }
            }
        }
    }
    printf("%d %d", num[c2], w[c2]);
    system("pause");
    return 0;
}