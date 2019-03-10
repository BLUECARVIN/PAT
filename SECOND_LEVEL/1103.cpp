#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, p, maxFacSum = -1;
// maxFacSum用来记录最大底数的和
vector<int> fac, ans, temp;
// fac记录使得i^p为不超过n的最大数
// ans存放最优底数序列，temp存放递归中的临时底数序列

int power(int x)
{
    int ans = 1;
    for(int i = 0; i < p; i++)
    {
        ans *= x;
    }
    return ans;
};

void init() //处理fac数组，把0也存进去
{
    int i = 0, temp = 0;
    while(temp <= n)
    {
        fac.push_back(temp);
        temp = power(++i);
    }
};

// DFS函数，当前访问fac[index], nowK为当前选中的个数
// sum 为当前选中的和，facsum为当前选中的底数的和
void DFS(int index, int nowK, int sum, int facSum)
{
    if(sum == n && nowK == k) //找到一个满足条件的序列
    {
        if(facSum > maxFacSum)
        {
            ans = temp; //更新最优底数序列
            maxFacSum = facSum; //更新最大底数之和
        }
        return;
    }
    if(sum > n || nowK > k) return;
    if(index - 1 > 0) // fac[0]不需要选择
    {
        temp.push_back(index); // 把底数index加入临时序列temp
        DFS(index, nowK + 1, sum + fac[index], facSum + index);
        temp.pop_back(); //选的分支后把刚加进去的去除
        DFS(index - 1, nowK, sum, facSum);
    }
}

int main()
{
    scanf("%d%d%d", &n, &k, &p);
    init();
    DFS(fac.size() - 1, 0, 0, 0); //从fac的最后一位向前搜索
    if(maxFacSum == -1) printf("Impossible\n"); 
    else
    {
        printf("%d = %d^%d", n, ans[0], p);
        for(int i = 1; i < ans.size(); i++)
        {
            printf(" + %d^%d", ans[i], p);
        }
    }
    return 0;
}