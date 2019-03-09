// case3 timeout
#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int num = 1;
    int k;
    vector<int> ans;
    int sum = 0;
    for(int i = 0; i <= num; i++)
    {
        if (i==0)
        {
            scanf("%d", &num);
            ans.push_back(0);
        }
        else
        {
            scanf("%d", &k);
            ans.push_back(k);
            sum += k;
        }
    }
    int t;
    vector<int> A;
    scanf("%d", &t);
    for(int i = 0; i < t; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        if(a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }
        int sum1 = 0;
        for(int j = a; j < b; j++)
        {
            sum1 += ans[j];
        }
        if(sum1 < sum - sum1)
        {
            A.push_back(sum1);
        }
        else
        {
            A.push_back(sum - sum1);
        }
        
    }
    for(int i = 0; i < A.size(); i++)
    {
        printf("%d\n", A[i]);
    }
    system("pause");
    return 0;
}