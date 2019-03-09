#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int address;
    int val;
    int next;
    int flag;
}List[100010], p;

bool cmp(ListNode a, ListNode b)
{
    if(a.flag == 0 || b.flag == 0)
    {
        return a.flag > b.flag;
    }
    else
    {
        return a.val < b.val;
    }
};

int main()
{
    for(int i = 0; i < 100010; i++)
    {
        List[i].flag = 0;
    }
    int n, begin, address;
    scanf("%d %d", &n, &begin);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &address);
        scanf("%d %d", &List[address].val, &List[address].next);
        List[address].address = address;
    }
    int count = 0, p = begin;
    while(p != -1)
    {
        List[p].flag = 1;
        count ++;
        p = List[p].next;
    }
    if(count == 0)
    {
        printf("0 -1");
    }
    else
    {
        sort(&List[0], &List[100010], cmp);
        printf("%d %05d\n", count, List[0].address);
        for(int i = 0; i < count; i++)
        {
            if(i != count - 1)
            {
                printf("%05d %d %05d\n", List[i].address, List[i].val, List[i].next);
            }
            else
            {
                printf("%05d %d -1\n", List[i].address, List[i].val);
            }
        }
    }
    system("pause");
    return 0;
}


