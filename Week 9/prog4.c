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

int main()
{
    int n;
    scanf("%d",&n);
    int val;
    if(n==0) return 0;;
    scanf("%d",&val);
    TreeNode node = {val,NULL,NULL};
    TreeNode* root = &node;
    for(int i = 1 ; i< n ; i++)
    {
        scanf("%d",&val);
        insert(root, val);
    }
    
    TreeNode* q[10000]; int f = 0; int b = -1;
    q[++b] = root;
    int i =0 ;
    while(f<=b)
    {
        int size = b - f+1;
        if(i%2 == 0) // left to right
        {
            for(int j = 0; j< size; j++)
            {
                TreeNode* temp = q[f+j];
                printf("%d ",temp->val);
            }
        }
        else
        {
            for(int j = size-1; j>=0; j--) //right to left;
            {
                TreeNode* temp = q[f + j];
                printf("%d ",temp->val);
            }
        }
        i++;
        for(int j = 0; j< size; j++)
        {
            TreeNode* temp = q[f++];
            if(temp->left != NULL) q[++b] = temp->left;
            if(temp->right != NULL) q[++b] = temp->right;    
        }

    }
       
    return 0;

}

