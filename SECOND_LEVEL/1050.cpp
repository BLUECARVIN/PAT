#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char s1[10010];
    char s2[10010];
    cin.getline(s1, 10000);
    cin.getline(s2, 10000);
    bool HashTable[128] = {false};
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    for (int i = 0; i < len2; i++)
    {
        HashTable[s2[i]] = true;
    }
    for(int i = 0; i < len1; i++)
    {
        if(HashTable[s1[i]] == false)
        {
            printf("%c", s1[i]);
        }
    }
    system("pause");
    return 0;
}