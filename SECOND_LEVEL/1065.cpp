#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num, tcase = 1;
    scanf("%d", &num);
    vector<int> ans;
    while(num--)
    { 
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long res = a + b;
        int flag;
        if(a > 0 && b > 0 && res < 0) flag = true;
        else if(a < 0 && b < 0 && res >= 0) flag = false;
        else if(res > c) flag = true;
        else flag = false;
        if(flag == true)
        {
            ans.push_back(1);
        }
        else
        {
            ans.push_back(0);
        }
    }
    for(int i = 0; i < ans.size(); i++)
    {
        if(ans[i] == 1)
        {
            printf("Case #%d: true\n", i+1);
        }
        else
        {
            printf("Case #%d: false\n", i+1);
        }
        
    }
    system("pause");
    return 0;
}