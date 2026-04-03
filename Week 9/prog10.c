#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
} TreeNode;

void insert(TreeNode* root, int v)
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
            return ;
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
            return ;
        }
        else insert(root->right,v);
    }
}
int subtreesum(TreeNode* node)
{
    if(node == NULL) return 0;
    int l = subtreesum(node->left);
    int r = subtreesum(node->right);
    return l+r+node->val;
}

TreeNode * find(TreeNode* node, int v)
{
    if(node == NULL) return NULL;
    if(node->val == v) return node;
    TreeNode* l = find(node->left, v);
    TreeNode* r = find(node->right,v);
    if(l==NULL) return r;
    else return l;
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
    for(int i = 1 ; i< n ; i++)
    {
        scanf("%d",&val);
        insert(root, val);
    }
    int k;
    scanf("%d",&k);
    TreeNode* kn = find(root,k);
    printf("%d\n",subtreesum(kn));
    return 0;
}

