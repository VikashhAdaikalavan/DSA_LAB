#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node* next;
    
}node;

int main()
{
    //inputs
    int n;
    node* prev = NULL;
    node* head = NULL;
    scanf("%d",&n);
    for(int i = 0; i<n ; i++)
    {
        node* temp = (node*)malloc(sizeof(node));
        temp->next = NULL;
        scanf("%d",&(temp->val));
        if(head == NULL)
        {
            head = temp;
            prev = temp;
        }
        else
        {
            prev->next = temp;
            prev = temp;
        }
    }
    node* temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        if(temp->next->val<= temp->val)
        {
            if(temp->next != NULL) temp->next = temp->next->next;
            else temp->next = NULL;
        }
        temp = temp->next;
    }
    

    //printing
    temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    return 0;
}