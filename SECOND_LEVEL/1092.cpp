#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1010;
char Buy[maxn], Want[maxn];
int Hash[26 * 2 + 10] = {0};

int main()
{
    cin.getline(Buy, 1000);
    cin.getline(Want, 1000);
    int len1 = strlen(Buy);
    int len2 = strlen(Want);
    for(int i = 0; i < len1; i++) //每遍历一个珠子，将对应位置的hash值++
    {
        if(Buy[i] >= 'a' && Buy[i] <= 'z') Hash[Buy[i] - 'a']++;
        else if(Buy[i] >= 'A' && Buy[i] <= 'Z') Hash[Buy[i] - 'A' + 26]++;
        else Hash[Buy[i] - '0' + 52] ++;
    }
    for (int i = 0; i < len2; i++) //每需要一颗珠子，将对应位置的hash值--
    {
        if(Want[i] >= 'a' && Want[i] <= 'z') Hash[Want[i] - 'a']--;
        else if(Want[i] >= 'A' && Want[i] <= 'Z') Hash[Want[i] - 'A' + 26]--;
        else Hash[Want[i] - '0' + 52]--;
    }
    int miss = 0; //记录Hash中缺失的珠子个数
    for(int i = 0; i < 26*2+10; i++)
    {
        if(Hash[i] < 0)
        {
            miss++;
        }
    }
    if(miss == 0) //没有缺失的珠子说明能满足需要
    {
        printf("Yes %d\n", len1 - len2);
    }
    else //出现sum_neg 小于零则说明有缺失的珠子，则不能满足需要
    {
        printf("No %d\n", miss);
    }
    
    system("pause");
    return 0;
}