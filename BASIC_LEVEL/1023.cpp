#include <cstdio>
#include <iostream>

using namespace std;
int hashTable[10] = {0};

int main()
{
    for(int i = 0; i < 10; i++)
    {
        int k;
        scanf("%d", &k);
        hashTable[i] = k;
    }
    for(int i = 1; i < 10; i++)
    {
        if(hashTable[i] != 0)
        {
            printf("%d", i);
            hashTable[i] --;
            break;
        }
    }
    for(int i = 0; i < 10; i++)
    {
        while(hashTable[i] != 0)
        {
            printf("%d", i);
            hashTable[i] --;
        }        
    }
    system("pause");
    return 0;    
}