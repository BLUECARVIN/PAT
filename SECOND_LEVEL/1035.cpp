#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct Node
{
    char id[1010];
    char password[1010];
};

int main()
{
    int num;
    scanf("%d", &num);
    vector<Node> A;
    while(num--)
    {
        Node temp;
        scanf("%s %s", &temp.id, &temp.password);
        A.push_back(temp);
    }
    int sum = 0;
    vector<int> ans;
    for(int i = 0; i < A.size(); i++)
    {
        int len = strlen(A[i].password), flag = 0;
        for(int j = 0; j < len; j++)
        {
            if(A[i].password[j] == '1')  
            {
                A[i].password[j] = '@';
                flag = 1;
            }
            else if(A[i].password[j] == 'l') 
            {
                A[i].password[j] = 'L';
                flag = 1;
            }
            else if(A[i].password[j] == 'O') 
            {
                A[i].password[j] = 'o';
                flag = 1;
            }
            else if(A[i].password[j] == '0') 
            {
                A[i].password[j] = '%';
                flag = 1;
            }
        }
        if(flag == 1)
        {
            ans.push_back(i);
            sum ++;
            flag = 0;
        }
    }
    if(sum == 0 && num == 1)
    {
        printf("There is 1 account and no account is modified\n");
    }
    else if(sum == 0 && num != 1)
    {
        printf("There are %d accounts and no account is modified\n");
    }
    else
    {
        printf("%d\n", sum);
    }
    for(int i = 0; i < sum; i++)
    {
        printf("%s %s\n", A[ans[i]].id, A[ans[i]].password);
    }
    system("pause");
    return 0;
}