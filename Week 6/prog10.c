#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* right;
    struct node* down;
} node;

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i = 0 ; i< n ; i++)
        for(int j = 0; j< n; j++)
            scanf("%d",&arr[i][j]);

    node* head = NULL;
    node* tempb = NULL;
    for(int i = 0; i< n ; i++)
    {
        node* newnodebase = (node*)(malloc(sizeof(node)));
        newnodebase->down = NULL;
        newnodebase->right = NULL;
        if(head == NULL) 
        {
            head = newnodebase;
            tempb = newnodebase;
        }
        else
        {
            tempb->down = newnodebase;
            tempb = newnodebase;
        }
        newnodebase->val = i;
        node* tempr = tempb;
        for(int j = 0; j< n ; j++)
        {
            if(arr[i][j] == 1)
            {
                node* newnode = (node*)(malloc(sizeof(node)));
                newnode->right = NULL;
                newnode->down = NULL;
                newnode->val = j;
                tempr->right = newnode;
                tempr = newnode;
            }

        }
    }
    printf("\n");
    tempb = head;
    node * tempr = head;
    while(tempb != NULL)
    {
        tempr = tempb;
        while(tempr != NULL)
        {
            if(tempr->right == NULL)
            {
                printf("%d\n",tempr->val);
            }
            else printf("%d -> ",tempr->val);
            tempr = tempr-> right;
        }
        if(tempb->down != NULL) printf("|\n");
        tempb = tempb->down;
    }
    return 0;
}