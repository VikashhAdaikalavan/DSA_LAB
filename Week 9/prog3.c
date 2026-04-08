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

void inorder(TreeNode* root, int* arr, int *i)
{
    if(root == NULL) return;
    inorder(root->left,arr,i);
    arr[(*i)++] = root->val;
    inorder(root->right,arr,i);
    return;
}
    
int countInRange(TreeNode* root, int u, int v)
{
    if(root == NULL) return 0;

    if(root->val < u)
        return countInRange(root->right, u, v);

    if(root->val > v)
        return countInRange(root->left, u, v);

    return 1 + countInRange(root->left, u, v)
             + countInRange(root->right, u, v);
}

int main()
{
    int n;
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
    int arr[n];
    int i =0;
    inorder(root,arr,&i);
    int u,v;
    scanf("%d %d",&u,&v);
    int c = 0;
    for(int i =0; i< n ; i++)
    {
        if(arr[i]>=u && arr[i]<=v) c++;
    }
    printf("%d\n",c);    
    return 0;

}

