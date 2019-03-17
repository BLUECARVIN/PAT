#include <cstdio>
#include <iostream>

using namespace std;

int n;

struct Fra
{
    int up;
    int down;
};

int gcd(int a, int b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}

Fra add(Fra a, Fra b)
{
    Fra ans ;
    ans.up = a.up * b.down + b.up * a.down;
    ans.down = a.down * b.down;
    return ans;
}

Fra Sim(Fra a)
{
    if(a.down < 0)
    {
        a.down = -a.down;
        a.up = - a.up;
    }
    if(a.up == 0)
    {
        a.down = 1;
    }
    int d = gcd(abs(a.up), abs(a.down));
    if(d != 1)
    {
        a.up /= d;
        a.down /= d;
    }
    return a;
}

int main()
{
    Fra sum ;
    sum.down = 1;
    sum.up = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        Fra a;
        scanf("%d/%d", &a.up, &a.down);
        sum = add(sum, a);
    }
    sum = Sim(sum);
    if(sum.up > sum.down)
    {
        printf("%d", sum.up / sum.down);
        sum.up = sum.up % sum.down;
        if(sum.up != 0)
        {
            printf(" ");
        }
        else
        {
            system("pause");
            return 0;
        }
    }
    if(sum.up != 0)
        printf("%d/%d", sum.up, sum.down);
    else
    {
        printf("0");
    }
        
    system("pause");
    return 0;
}