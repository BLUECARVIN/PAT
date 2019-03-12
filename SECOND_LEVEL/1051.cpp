#include <iostream>
#include <cstdio>
#include <queue>
#include <stack>

using namespace std;

const int maxn = 1010;
int arr[maxn];

int main()
{
    int n, m, k;
    scanf("%d %d %d", &m, &n, &k);
    queue<bool> Q;
    stack<int> s;
    while(k --)
    {
        while(!s.empty()) //清空栈
        {
            s.pop();
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        bool flag = true;
        int current = 1;
        for(int i = 1; i <= n; i++)
        {
            s.push(i);
            if(s.size() > m)
            {
                flag = false;
                break;
            }
            while(!s.empty() && s.top() == arr[current])
            {
                s.pop();
                current ++;
            }
        }
        if(s.empty() == true && flag == true)
        {
            Q.push(true);
        }
        else
        {
            Q.push(false);
        }
        
    }
    while(!Q.empty())
    {
        if(Q.front() == true)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        Q.pop();
    }
    system("pause");
    return 0;    
}