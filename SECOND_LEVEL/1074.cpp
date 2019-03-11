#include <cstdio>
#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

const int maxn = 100011;
int n, k, first;

struct Node
{
    int data;
    int next;
}List[maxn];

int main()
{
    scanf("%d %d %d", &first, &n, &k);
    for(int i = 0; i < n; i ++)
    {
        int address;
        scanf("%d", &address);
        scanf("%d %d", &List[address].data, &List[address].next);
    }
    stack<int> s;
    List[100010].next = first;
    int p = first;
    int q = 100010;
    int i = 1;
    int l = 0;
    while(n - k*i >= 0)
    {
        for(int i = 0; i < k; i++)
        {
            s.push(p);
            p = List[p].next;
        }
        for(int i = 0; i < k; i++)
        {
            int t = s.top();
            List[q].next = t;
            q = t;
            s.pop();
        }
        l += k;
        i++;
        if(p == -1) break;
    }
    while(p != -1)
    {
        List[q].next = p;
        q = p;
        p = List[p].next;
        l ++;
    }
    // cout << l << endl;
    first = List[100010].next;
    p = first;
    // printf("%5d", List[first].next);
    for(int i = 0; i < l; i++)
    {
        if(i != l - 1)
            printf("%05d %d %05d\n", p, List[p].data, List[p].next);
        else
        {
            printf("%05d %d -1\n", p, List[p].data);
        }
        
        p = List[p].next;
    }
    system("pause");
    return 0;
}

// 00000 6 3
// 00000 1 11111
// 11111 2 22222
// 22222 3 -1
// 33333 4 44444
// 44444 5 55555
// 55555 6 -1