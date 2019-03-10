#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAXV = 1010;
struct Node
{
    int id; //结点编号
    int layer; //结点层号
};

vector<Node> Adj[MAXV];
bool inq[MAXV] = {false};
int n, max_layer;

int BFS(int s, int l) //s为开始结点， l为层数上限
{
    int numForward = 0;
    queue<Node> q;
    Node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true; 
    while(!q.empty())
    {
        Node topNode = q.front();
        q.pop();
        int u = topNode.id;
        for (int i = 0; i < Adj[u].size(); i++)
        {
            Node next = Adj[u][i]; // 此u出发能到达的结点next;
            next.layer = topNode.layer + 1;
            if(inq[next.id] == false && next.layer <= l)
            {
                q.push(next);
                inq[next.id] = true;
                numForward ++;
            }
        }
    }
    return numForward;
};

int main()
{
    Node user;
    int numFollow, idFollow;
    scanf("%d %d", &n, &max_layer);
    for(int i = 1; i <= n; i++)
    {
        user.id = i;
        scanf("%d", &numFollow);
        for(int j = 0; j < numFollow; j++)
        {
            scanf("%d", &idFollow); // i用户关注的编号
            Adj[idFollow].push_back(user);
        }
    }
    int numQuery, s;
    scanf("%d", &numQuery);
    for(int i = 0; i < numQuery; i++)
    {
        memset(inq, false, sizeof(inq));
        scanf("%d", &s);
        int ans = BFS(s, max_layer);
        printf("%d\n", ans);
    }
    system("pause");
    return 0; 
}