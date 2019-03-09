#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    char str1[100], str2[100];
    bool HashTable[128] = {false};  //hashtable 用来标记字符是否已输出
    cin.getline(str1, 100);
    cin.getline(str2, 100);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i = 0; i < len1; i++) //枚举第一个字符串中的字符
    {
        int j;
        char c1, c2;
        for(j = 0; j < len2; j++) //枚举第二个字符串中的字符
        {
            c1 = str1[i];
            c2 = str2[j];
            if(c1 >= 'a' && c1 <= 'z') c1 -= 32;
            if(c2 >= 'a' && c2 <= 'z') c2 -= 32;
            if(c1 == c2) break;
        }
        if(j == len2 && HashTable[c1] == false)
        {
            printf("%c", c1);
            HashTable[c1] = true;
        }
    }
    return 0;
}