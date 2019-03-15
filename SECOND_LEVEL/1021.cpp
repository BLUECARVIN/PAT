#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int maxn = 10010;
vector<int> G[maxn];
int INF = 1e+9;
int n, deep = 0;
int visited[maxn] = {0};

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int s, d;
        scanf("%d %d", &s, &d);
        G[s].push_back(d);
        G[d].push_back(s);
    }
}