#include <cstdio>
#include <iostream>

using namespace std;

int k[200005];

int main()
{
    int n, m;
    scanf("%d", &n);
    for(int i = 1; i < n; i++)
    {
        scanf("%d", &k[i]);
    }
    k[n + 1] = 0x7fffffff;
    scanf("%d", &m);
    int count = 0, median;
    median = (n + m - 1) / 2;
    int num;
    int i = 1;
    for(int j = 0; j < m; j++)
    {
        scanf("%d", &num);
        while(k[i] < num)
        {
            count ++;
            if(count == median)
            {
                cout << k[i];
                system("pause");
                return 0;
            }
        }
        count ++;
        if(count == median)
        {
            cout << num;
            system("pause");
            return 0;
        }
    }
    while(i <= n)
    {
        count ++;
        if(count == median )
        {
            cout << k[i];
            system("pause");
            return 0;   
        }
        i++;
    }
}