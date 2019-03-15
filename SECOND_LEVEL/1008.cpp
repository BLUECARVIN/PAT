#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int n, sum = 0;
    vector<int> sq;
    sq.push_back(0);
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        sq.push_back(k);
    }
    for(int i = 1; i <= n; i++)
    {
        int d = sq[i] - sq[i - 1];
        if(d > 0)
        {
            sum += d * 6;
        }
        else
        {
            sum += -d * 4;
        }
    }
    sum += n * 5;
    printf("%d", sum);
    system("pause");
    return 0;
}