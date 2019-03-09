#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 22;
int data[maxn];

struct TreeNode
{
    int val, height;
    TreeNode* lchild;
    TreeNode* rchild;
};

TreeNode* newNode(int x)
{
    TreeNode* Node = new TreeNode;
    Node->val = x;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
};

int getHeight(TreeNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    return root->height;
};

int getBalanceFactor(TreeNode* root)
{
    return (getHeight(root->lchild) - getHeight(root->rchild));
};

void updateHeight(TreeNode* root)
{
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
};

void R(TreeNode* &root)
{
    TreeNode* temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
};
void L(TreeNode* &root)
{
    TreeNode* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
};

void insert(TreeNode* &root, int v)
{
    if(root == NULL)
    {
        root = newNode(v);
        return;
    }
    if(v < root->val)
    {
        insert(root->lchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(root->lchild) == 1)
            {
                R(root);
            }
            else if(getBalanceFactor(root->lchild) == -1)
            {
                L(root->lchild);
                R(root);
            }
        }
    }
    else
    {
        insert(root->rchild, v);
        updateHeight(root);
        if(getBalanceFactor(root) == 2)
        {
            if(getBalanceFactor(root->rchild) == -1)
            {
                L(root);
            }
            else if(getBalanceFactor(root->rchild) == 1)
            {
                R(root->rchild);
                L(root);
            }
        }
    }
};

TreeNode* Creat(int data[], int n)
{
    TreeNode* root = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(root, data[i]);
    }
    return root;
};

int main()
{
    int n, v;
    TreeNode* root = NULL;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &v);
        insert(root, v);

    }
    system("pause");
    return 0;
}