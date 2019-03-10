#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int HashTable[600] = {0};
const int maxn = 100010;
int Coin[maxn];
int n, sum;

int main()
{
    scanf("%d %d", &n, &sum);
    for(int i = 0; i < n; i++) //输入硬币， HashTable记录硬币值对应的硬币个数，coin记录硬币
    {
        int k;
        scanf("%d", &k);
        Coin[i] = k;
        HashTable[k] ++;
    }
    sort(Coin, Coin + n); //将硬币从小到大排序
    for(int i = 0; i < n; i++)
    {
        if(sum - Coin[i] == Coin[i]) //若用两个相同面值的硬币可以支付
        {
            if(HashTable[Coin[i]] > 1)
            {
                printf("%d %d", Coin[i], Coin[i]);
                system("pause");
                return 0;
            }
        }
        else //用不同面值的硬币支付
        {
            if(HashTable[sum - Coin[i]] > 0)  //对应所需要的硬币个数大于0
            {
                printf("%d %d", Coin[i], sum - Coin[i]);
                system("pause");
                return 0;
            }
        }
    }
    printf("No Solution");
    system("pause");
    return 0;
}