#include <cstdio>
#include <string>
#include <iostream>

char Num[11][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

using namespace std;

int main()
{
    string s;
    cin >> s;
    long long sum = 0;
    string ans;
    for (int i = 0; i < s.size(); i++)
    {
        sum += (s[i] - '0');
    }
    ans = to_string(sum);
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%s", Num[ans[i] - '0']);
        if(i != ans.size() - 1)
        {
            printf(" ");
        }
    }
    system("pause");
    return 0;
}