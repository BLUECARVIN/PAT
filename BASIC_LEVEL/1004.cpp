#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1000000;
int n;

struct Node
{
    char name[15];
    char id[15];
    int score;
}List[maxn];

bool cmp(Node a, Node b)
{
    return a.score > b.score;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &List[i].name, &List[i].id, &List[i].score);
    }
    sort(List, List + n, cmp);
    printf("%s %s\n", List[0].name, List[0].id);
    printf("%s %s\n", List[n - 1].name, List[n - 1].id);
    return 0;
}