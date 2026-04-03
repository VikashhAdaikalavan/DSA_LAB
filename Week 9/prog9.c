#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    int colour; // 1 = RED, 0 = BLACK
    struct node* left;
    struct node* right;
    struct node* par;
} TreeNode;

TreeNode* createNode(int val)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->colour = 1; // new node is RED
    node->left = node->right = node->par = NULL;
    return node;
}

// LEFT ROTATE
void lrotate(TreeNode** root, TreeNode* x)
{
    TreeNode* y = x->right;
    x->right = y->left;

    if(y->left != NULL)
        y->left->par = x;

    y->par = x->par;

    if(x->par == NULL)
        *root = y;
    else if(x == x->par->left)
        x->par->left = y;
    else
        x->par->right = y;

    y->left = x;
    x->par = y;
}

// RIGHT ROTATE
void rrotate(TreeNode** root, TreeNode* x)
{
    TreeNode* y = x->left;
    x->left = y->right;

    if(y->right != NULL)
        y->right->par = x;

    y->par = x->par;

    if(x->par == NULL)
        *root = y;
    else if(x == x->par->left)
        x->par->left = y;
    else
        x->par->right = y;

    y->right = x;
    x->par = y;
}

// FIX RED-BLACK PROPERTIES
void fixup(TreeNode** root, TreeNode* z)
{
    while(z != *root && z->par->colour == 1)
    {
        TreeNode* parent = z->par;
        TreeNode* grand = parent->par;

        if(parent == grand->left)
        {
            TreeNode* uncle = grand->right;

            // Case 1: Uncle is RED
            if(uncle != NULL && uncle->colour == 1)
            {
                parent->colour = 0;
                uncle->colour = 0;
                grand->colour = 1;
                z = grand;
            }
            else
            {
                // Case 2: Left-Right
                if(z == parent->right)
                {
                    z = parent;
                    lrotate(root, z);
                    parent = z->par;
                }

                // Case 3: Left-Left
                parent->colour = 0;
                grand->colour = 1;
                rrotate(root, grand);
                parent = z->par;
            }
        }
        else
        {
            TreeNode* uncle = grand->left;

            // Case 1: Uncle is RED
            if(uncle != NULL && uncle->colour == 1)
            {
                parent->colour = 0;
                uncle->colour = 0;
                grand->colour = 1;
                z = grand;
            }
            else
            {
                // Case 2: Right-Left
                if(z == parent->left)
                {
                    z = parent;
                    rrotate(root, z);
                }

                // Case 3: Right-Right
                parent->colour = 0;
                grand->colour = 1;
                lrotate(root, grand);
            }
        }
    }

    (*root)->colour = 0; // root always BLACK
}

// BST INSERT + FIXUP
void insert(TreeNode** root, int val)
{
    TreeNode* z = createNode(val);
    TreeNode* y = NULL;
    TreeNode* x = *root;

    while(x != NULL)
    {
        y = x;
        if(val < x->val)
            x = x->left;
        else
            x = x->right;
    }

    z->par = y;

    if(y == NULL)
        *root = z;
    else if(val < y->val)
        y->left = z;
    else
        y->right = z;

    fixup(root, z);
}

// MAIN
int main()
{
    int n, val;
    scanf("%d", &n);

    TreeNode* root = NULL;

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &val);
        insert(&root, val);
    }

    TreeNode* temp = root;
    int c = 0;
    while(temp != NULL)
    {
        if(temp->colour == 0) c++;
        temp = temp->left;
    }

    printf("%d \n",c);

    return 0;
}