#include <cstdio>
#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main()
{
    char input[85], type[85], ans[85];
    cin.getline(input, 85);
    cin.getline(type, 85);
    int len = strlen(type);
    int len2 = strlen(input);
    map<char, int> m;
    for(int i = 0; i < len; i++)
    {
        if(type[i] - 'a' >= 0 && 'z' - type[i] >= 0)
        {
            type[i] -= 32;
            // printf("%c", type[i]);
        }
        if(m.find(type[i]) == m.end())
        {
            m[type[i]] = 1;
        }
    }
    int j = 0;
    for(int i = 0; i < len2; i++)
    {
        if(input[i] - 'a' >= 0 && 'z' - input[i] >= 0)
        {
            input[i] -= 32;
        }
        if(m.find(input[i]) == m.end())
        {
            ans[j++] = input[i];
            m[input[i]] = 1;
        }
    }
    int len3 = strlen(ans);
    for(int i = 0; i < len3; i++)
    {
        printf("%c", ans[i]);
    }
    system("pause");
    return 0;
}