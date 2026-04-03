#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
} TreeNode;

TreeNode* insert(TreeNode* root, int v)
{
    if(root->val>v)
    {
        if(root->left == NULL)
        {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->left = NULL;
            node->right = NULL;
            node->val = v;
            root->left = node;
            return node;
        }
        else insert(root->left,v);
    }
    else
    {
        if(root->right == NULL)
        {
            TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
            node->left = NULL;
            node->right = NULL;
            node->val = v;
            root->right = node;
            return node;
        }
        else insert(root->right,v);
    }
}

int children(TreeNode* root)
{
    if(root == NULL) return 0;
    int l = children(root->left);
    int r = children(root->right);
    return l+r+1;
}

int main()
{
    int n,u,v;
    scanf("%d",&n);
    int val;
    if(n==0) return 0;
    scanf("%d",&val);
    TreeNode node = {val,NULL,NULL};
    TreeNode* root = &node;
    TreeNode* arr[n];
    arr[0] = root;
    for(int i = 1 ; i< n ; i++)
    {
        scanf("%d",&val);
        arr[i] = insert(root, val);
    }
    for(int i = 0; i< n ; i++)
    {
        printf("%d ",children(arr[i])-1);
    }
    return 0;

}


