#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> pre[510];
bool visited[510];
int n, m, s, de, INF = 1e+9;
vector<int> temp, best;
int G[510][510], d[510], weight[510][510];
int opt = INF;

void Dijkstra(int s)
{
    fill(d, d + 510, INF);
    fill(visited, visited + 510, false);
    d[s] = 0;
    for(int i = 0; i < n; i++)
    {
        int u = -1, min = INF;
        for(int j = 0; j < n; j++)
        {
            if(visited[j] == false && d[j] < min)
            {
                u = j;
                min = d[j];
            }
        }
        if(u == -1) break;
        visited[u] = true;
        for(int v = 0; v < n; v++)
        {
            if(visited[v] == false && G[u][v] != INF)
            {
                if(d[u] + G[u][v] < d[v])
                {
                    pre[v].clear();
                    d[v] = d[u] + G[u][v];
                    pre[v].push_back(u);
                }
                else if(d[u] + G[u][v] == d[v])
                {
                    pre[v].push_back(u);
                }
            }
        }
    }
}

void DFS(int v)
{
    if(v == s)
    {
        temp.push_back(v);
        int value = 0;
        for(int i = temp.size() - 1; i > 0; i--)
        {
            cout << temp[i];
            value += weight[temp[i]][temp[i - 1]];
        }
        cout << endl;
        if(value < opt)
        {
            opt = value;
            best = temp;
        }
        temp.pop_back();
        return;
    }    
    temp.push_back(v);
    for(int i = 0; i < pre[v].size(); i++)
    {
        DFS(pre[v][i]);
    }
    temp.pop_back();
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &de);
    int u, v;
    fill(G[0], G[0]+510*510, INF);
    fill(weight[0], weight[0]+ 510 * 510, INF);
    for(int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        scanf("%d %d", &G[u][v], &weight[u][v]);
        G[v][u] = G[u][v];
        weight[v][u] = weight[u][v];
    }
    Dijkstra(s);
    DFS(de);
    for(int i = best.size() - 1; i >= 0; i--)
    {
        printf("%d ", best[i]);
    }
    int sum = 0;
    for(int i = best.size() - 1; i > 0; i--)
    {
        sum += G[best[i]][best[i-1]];
    }
    printf("%d %d", sum, opt);
    system("pause");
    return 0;
    
}