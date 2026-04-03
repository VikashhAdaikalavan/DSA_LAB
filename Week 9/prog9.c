#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int colour; // 1 if for red, 0 is for black
    struct node* left;
    struct node* right;
    struct node* par;
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
            node->colour = 1;
            node->par = root;
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
            node->colour = 1;
            node->par = root;
            root->right = node;
            return ;
        }
        else insert(root->right,v);
    }
    fixup(node);
}

void rotate(TreeNode* node)
{
    TreeNode parent = 
}

void fixup(TreeNode* node)
{
    
}