#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxn = 100010;

struct Node
{
    char name[15];
    char id[15];
    int grade;
}List[maxn];

bool cmp (Node a, Node b)
{
    return a.grade >= b.grade;
}

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%s %s %d", &List[i].name, &List[i].id, &List[i].grade);
    }
    int min, max;
    scanf("%d %d", &min, &max);
    int sum = 0;
    sort(List, List + n, cmp);
    if(List[0].grade < min)
    {
        printf("NONE\n");
    }
    int k;
    for(k = 0; k < n; k++)
    {
        if(List[k].grade <= max)
        {
            break;
        }
    }
    for(int i = k; i < n; i++)
    {
        if(List[i].grade >= min)
        {
            sum ++;
        }
        else
        {
            break;
        }
    }
    printf("%d\n", sum);
    for(int i = k; i < k+ sum; i++)
    {
        printf("%s %s\n", &List[i].name, &List[i].id);
    }
    system("pause");
    return 0;
}