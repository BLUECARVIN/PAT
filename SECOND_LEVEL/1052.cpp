#include <cstdio>
#include <iostream>
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10010;
int sum = 0;

struct Node
{
    int add;
    int data;
    int next;
}List[maxn];


bool cmp(Node a, Node b)
{
    if(a.data != b.data)
        return a.data < b.data;
    else 
        return a.add < b.add;
}

int main()
{
    int n, first;
    scanf("%d %d", &n, &first);
    for(int i = 0; i < n; i++)
    {
        int k;
        cout << i<< endl;
        scanf("%d", &k);
        scanf("%d %d", &List[k].data, &List[k].next);
        List[k].add = k;
    }
    int p = first;
    vector<Node> Record;
    while(p != -1)
    {
        Record.push_back(List[p]);
        p = List[p].next;
        sum ++;
    }
    sort(Record.begin(), Record.end(), cmp);
    printf("%d %d\n", sum, Record[0].add);
    for(int i = 0; i < sum; i++)
    {
        if (i != sum - 1)
        {
            printf("%05d %d %05d\n", Record[i].add, Record[i].data, Record[i+1].add);
        }
        else
        {
            printf("%05d %d -1\n", Record[i].add, Record[i].data);
        }
    }
    system("pause");
    return 0;
}