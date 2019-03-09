#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a + b;
    string d;
    d = to_string(abs(c));
    if(c < 0)
    {
        cout << "-";
    }
    int j = d.size() % 3;
    if (j != 0)
    {
        j = 3 - j;
    }
    for(int i = 0; i < d.size(); i++)
    {
        if(j == 3)
        {
            j = 0;
            printf(",");
        }
        printf("%c", d[i]);
        j++;
    }
    cout << endl;
    cout <<j; 
    system("pause");
    return 0;

}