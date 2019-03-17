#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 10010;
char s[maxn];
int P[maxn], T[maxn];
long long sum = 0;

int main()
{
    cin.getline(s, 10000);
    int len = strlen(s);
    if(s[0] == 'P')
    {
        P[0] = 1;
    }
    for(int i = 1; i < len; i++)
    {
        P[i] = P[i - 1];
        if(s[i] == 'P')
        {
            P[i]++;
        }
    }
    if(s[len - 1] == 'T')
    {
        T[len - 1] = 1;
    }
    for(int i = len - 2; i >= 0; i--)
    {
        T[i] = T[i + 1];
        if(s[i] == 'T')
        {
            T[i] ++;
        }
    }
    for(int i = 0; i < len; i++)
    {
        if(s[i] == 'A')
        {
            sum += (long long)P[i] * T[i];
        }
    }
    printf("%lld", sum % 1000000007);
    system("pause");
    return 0;
}