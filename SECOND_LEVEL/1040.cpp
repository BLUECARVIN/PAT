#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1010;
char S[maxn];
int dp[maxn][maxn];

int main()
{
    cin.getline(S, 1005);
    cout << S << endl;
    int len = strlen(S);
    cout << len;
    memset(dp, 0, sizeof(dp));
    int ans = 1;
    for(int i = 0; i < len; i++)
    {
        dp[i][i] = 1;
        if( i < len - 1)
        {
            if(S[i] == S[i + 1])
            {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for(int L = 3; L <= len; L++)
    {
        for(int i = 0; L + i - 1 < len; i++)
        {
            int j = L + i - 1;
            if(S[i] == S[j] && dp[i + 1][j + 1] == 1)
            {
                dp[i][j] = 1;
                ans = L;
            }
        }
    }
    cout << ans << endl;
    system("pause");
    return 0;
}