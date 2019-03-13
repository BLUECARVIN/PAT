#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int main()
{
  vector<string> A = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi","ba",
    "jiu"};
  string s;
  cin >> s;
  int sum = 0;
  int st = int('0');
  for (int i = 0; i < s.size(); i++)
  {
    sum += int(s[i]) - st;
  }
  string ans = to_string(sum);
  for (int i = 0; i < ans.size(); i++)
  {
    int j = int(ans[i]) - st;
    cout << A[j];
    if(i != ans.size() - 1)
    {
      cout << " ";
    }
  }
  return 0;
}