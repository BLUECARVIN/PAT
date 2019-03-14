#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int maxn = 1010;
int n;
double d, sum = 0;

struct Cake
{
    double weight;
    double sale;
    double price;
}List[maxn];

bool cmp(Cake a, Cake b)
{
    return a.price > b.price;
}

int main()
{
    scanf("%d %lf", &n, &d);
    int m = d;
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf", &List[i].weight);
    }
    for(int i = 1; i <= n; i++)
    {
        scanf("%lf", &List[i].sale);
    }
    for(int i = 1; i <= n; i++)
    {
        List[i].price = List[i].sale / List[i].weight;
    }
    sort(&List[1], &List[n + 1], cmp);
     
    int k = 1;
    while(m > 0)
    {
        while(List[k].weight <= 0)
        {
            k++;
        }
        if(m - List[k].weight >= 0)
        {
            sum += List[k].sale;
            m -= List[k].weight;
            List[k].weight = 0;
        }
        else
        {
            sum += m * List[k].price;
            m = 0;
        }
    }
    printf("%.2lf\n", sum);
    system("pause");
    return 0; 
}