#include <cstdio>
#include <iostream>

using namespace std;

struct Node
{
    long long galleon;
    int sickle;
    int knut;
}a, b, sum;

int main()
{
    scanf("%lld.%d.%d %lld.%d.%d", &a.galleon, &a.sickle, &a.knut, &b.galleon, &b.sickle, &b.knut);
    int flag = 0;
    sum.knut = b.knut + a.knut;
    if(sum.knut > 28)
    {
        sum.knut = sum.knut % 29;
        flag = 1;
    }
    sum.sickle = a.sickle + b.sickle + flag;
    flag = 0;
    if(sum.sickle > 16)
    {
        sum.sickle = sum.sickle % 17;
        flag = 1;
    }
    sum.galleon = a.galleon + b.galleon + flag;
    printf("%lld.%d.%d", sum.galleon, sum.sickle, sum.knut);
    system("pause");
    return 0;
    
}