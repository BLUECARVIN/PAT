#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 510;
const int INF = 1e+9;

int G[maxn][maxn];
//num记录最短路径条数，w记录最大点权之和，d记录最短距离
int num[maxn], d[maxn], w[maxn], weight[maxn];
bool visited[maxn] = {false};
int n, m, st, ed;
//n记录顶点数，m记录边数，st，ed为起点和终点

void Dijkstra(int s)
{
    fill(d, d + maxn, INF);
    memset(num, 0, sizeof(num));
    memset(w, 0, sizeof(w));
    d[s] = 0;
    w[s] = weight[s];
    num[s] = 1;
    for(int i = 0; i < n; i++)
    {
        int u = -1, MIN = INF;
        for(int j = 0; j < n; j++)
        {
            if(visited[j] == false && d[j] < MIN)
            {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[v]; //更新权值和
                    num[v] = num[u]; 
                }
                else if(d[u] + G[u][v] == d[v]) //找到一条相同路径长度
                {
                    if(w[u] + weight[v] > w[v]) //以u为中介点时权值若更大
                    {
                        w[v] = w[u] + weight[v]; //更新权值
                    }
                    num[v] += num[u];
                }
            }
        }
    }
}

int main()
{
    scanf("%d %d %d", &n, &m, &st, &ed);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &weight[i]);
    }
    int u, v;
    fill(G[0], G[0] + maxn * maxn, INF);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d", &u, &v);
        scanf("%d", &G[u][v]);
        G[v][u] = G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n", num[ed], w[ed]);
    system("pause");
    return 0;
}