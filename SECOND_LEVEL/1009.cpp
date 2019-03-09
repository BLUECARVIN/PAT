#include <iostream>
#include <cstdio>

using namespace std;

struct Poly
{
    int exp;
    double k;
}poly[1001];

double ans[2001];

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    for(int i = 0; i < num1; i++)
    {
        scanf("%d %lf", &poly[i].exp, &poly[i].k);
    }
    scanf("%d", &num2);
    for(int i = 0; i < num2; i++)
    {
        int a;
        double b;
        scanf("%d %lf", &a, &b);
        for (int j = 0; j < num1; j++)
        {
            ans[a + poly[j].exp] += (b * poly[j].k);
        }
    }
    int num = 0;
    for(int i = 0; i <= 2000; i++)
    {
        if(ans[i] != 0.0) num++;
    }
    printf("%d", num);
    for(int i = 2000; i >=0; i --)
    {
        if(ans[i] != 0.0)
        {
            printf(" %d %.1f", i, ans[i]);
        }
    }
    return 0;
}