#include <cstdio>
#include <iostream>

int a[100001], HashTable[10001] = {0}; 

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        HashTable[a[i]] ++;
    }
    int ans = -1; //存放第一个出现的在序列中只有一个的数字
    for(int i = 0; i < n; i++)
    {
        if(HashTable[a[i]] == 1) //若只出现过一次
        {
            ans = a[i];
            break;
        }
    }
    if(ans == -1)
    {
        printf("None\n");
    }
    else
    {
        printf("%d\n", ans);
    }
    system("pause");
    return 0;
    
}