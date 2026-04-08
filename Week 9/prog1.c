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

void inorder(TreeNode* root)
{
    if(root == NULL) return;
    inorder(root->left);
    printf("%d ",root->val);
    inorder(root->right);
    return;
}

TreeNode* lca(TreeNode* node, int v , int u)
{
    if(node == NULL) return NULL;
    if(node->val == v || node->val == u) return node;
    TreeNode * l = lca(node->left,u,v);
    TreeNode* r = lca(node->right, u, v);
    if(l == NULL && r != NULL) return r;
    else if (l != NULL && r == NULL) return l;
    else if(l != NULL && r != NULL) return node;
    return NULL;
}

TreeNode* lcaBST(TreeNode* root, int u, int v)
{
    if(root == NULL) return NULL;

    if(root->val > u && root->val > v)
        return lcaBST(root->left, u, v);

    if(root->val < u && root->val < v)
        return lcaBST(root->right, u, v);

    return root; 
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
    scanf("%d %d",&u,&v);
    printf("%d\n",(lca(root, u, v))->val);
    return 0;

}

