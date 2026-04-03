#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    struct node* p;
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
            node->p = root;
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
            node->p = root;
            node->val = v;
            root->right = node;
            return ;
        }
        else insert(root->right,v);
    }
}

int pathsum(TreeNode* node, int b, TreeNode* prev)
{
    if(node == NULL) return -1;

    if(node->val == b) return node->val;

    int l = -1, r = -1, p = -1;

    if(node->left != prev)
        l = pathsum(node->left, b, node);

    if(node->right != prev)
        r = pathsum(node->right, b, node);

    if(node->p != prev)
        p = pathsum(node->p, b, node);

    if(l != -1) return l + node->val;
    if(r != -1) return r + node->val;
    if(p != -1) return p + node->val;

    return -1;
}

TreeNode* find(TreeNode* root, int a)
{
    if(root == NULL) return NULL;
    if(root->val == a) return root;
    TreeNode* l = find(root->left,a);
    TreeNode * r = find(root->right, a);
    if(l == NULL) return r;
    else return l;
}


int main()
{
    int n;
    scanf("%d",&n);
    int val;
    if(n==0) return 0;
    scanf("%d",&val);
    TreeNode node = {val,NULL,NULL,NULL};
    TreeNode* root = &node;
    for(int i = 1 ; i< n ; i++)
    {
        scanf("%d",&val);
        insert(root, val);
    }
    int a ,b;
    scanf("%d %d",&a,&b);
    TreeNode* an = find(root,a);
    printf("%d\n", pathsum(an, b, NULL));
    
    return 0;

}

