#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
char week[7][5] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
int main()
{
    char str1[70], str2[70], str3[70], str4[70];
    scanf("%s", &str1);
    scanf("%s", &str2);
    scanf("%s", &str3);
    scanf("%s", &str4);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);
    int i;
    for(i = 0; i < len1 && i < len2; i++)
    {
        if (str1[i] == str2[i] && str1[i] >= 'A' && str1[i] <= 'G')
        {
            printf("%s ", week[str1[i] - 'A']);
            break;
        }
    }
    for(i += 1;i<len1 && i < len2; i++)
    {
        if(str1[i] == str2[i])
        {
            if(str1[i] >= '0' && str1[i] <= '9')
            {
                printf("%02d:", str1[i] - '0');
                break;
            }
            if(str1[i] >= 'A' && str1[i] <= 'N')
            {
                printf("%02d:", str1[i] - 'A' + 10);
                break;
            }
        }
    }
    for(i = 0; i < len3 && i < len4; i++)
    {
        if(str3[i] == str4[i])
        {
            if((str3[i] >= 'A' && str3[i] <= 'Z') || (str3[i] >= 'a' && str3[i] <= 'z'))
            {
                printf("%02d", i);
                break;
            }
        }
    }
    system("pause");
    return 0;
}