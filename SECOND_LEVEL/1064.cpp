#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;
// n 为节点数，number用来存放权值，CBT用来存放完全二叉树
int n, number[maxn], CBT[maxn], index = 0;

void inOrder(int root)
{
    if(root > n)
        return;
    inOrder(root*2);
    CBT[root] = number[index++]; //按中序遍历，将排好序的数组填入CBT
    inOrder(root*2+1);
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &number[i]);
    }
    sort(&number[0], &number[n]); //将number排序，之后按中序顺序填入CBT
    inOrder(1);
    for(int i = 1; i <= n; i++)
    {
        printf("%d", CBT[i]);
        if(i != n)
        {
            printf(" ");
        }
    }
    return 0;
}