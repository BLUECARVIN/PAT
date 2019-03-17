#include <cstdio>
#include <iostream>

using namespace std;

const int maxn = 50010;
int n;
int pre[maxn], in[maxn];

struct TreeNode
{
    int val;
    TreeNode *left, *right;
};

TreeNode* Creat(int l_pre, int r_pre, int l_in, int r_in)
{
    if(l_pre > r_pre)
    {
        return NULL;
    }
    TreeNode* root = new TreeNode;
    root->val = pre[l_pre];
    int pos;
    for(int i = l_in; i <= r_in; i++)
    {
        if(in[i] == root->val)
        {
            pos = i;
            break;
        }
    }
    int left_len = pos - l_in;
    int right_len = r_in - pos;
    root->left = Creat(l_pre + 1, l_pre + left_len, l_in, pos - 1);
    root->right = Creat(l_pre + left_len + 1, r_pre, pos + 1, r_in);
    return root;
}

int main()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &pre[i]);
    }
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &in[i]);
    }
    TreeNode *root;
    root = Creat(0, n-1, 0, n-1);
    TreeNode *p = root;
    while(p->left || p->right)
    {
        if(p->left)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        
        }
    }
    printf("%d", p->val);
    system("pause");
    return 0;
}