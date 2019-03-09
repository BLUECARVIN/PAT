#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int max_na(double l, double m, double n, double max);
void print_ans(int a);

int main()
{
    int max_n[3];
    double x = 0, sum = 1;
    for(int i = 0; i < 3; i++)
    {
        double l, m, n;
        scanf("%lf %lf %lf", &l, &m, &n);
        x = max(l, max(m, n));
        sum *= x;
        max_n[i] = max_na(l, m, n, x);
    }
    sum = (sum * 0.65 - 1) * 2;
    for(int i = 0; i < 3; i++)
    {
        print_ans(max_n[i]);
    }
    printf("%.2f", sum);
    system("pause");
    return 0;    
}

int max_na(double l, double m, double n, double max)
{
    int ans;
    if (max == l) return 0;
    if (max == m) return 1;
    if (max == n) return 2;
}

void print_ans(int a)
{
    if (a == 0) printf("W ");
    if (a == 1) printf("T ");
    if (a == 2) printf("L ");
}
