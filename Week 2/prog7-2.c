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

    int x;
    scanf("%d", &x);
    prev = NULL;
    node* curr = head;
    node* last = head;
    while(last->next != NULL) last = last->next;
    node* tail = last;

    node* seqstart = NULL;
    node* curr = head;
    node* prev = NULL;
    node* head2 = NULL;
    
    while(curr != NULL)
    {
        if(curr->val == x)
        {
            if(head2 == NULL)
            {
                head2 = curr;
                seqstart = head2;
                prev = curr->next;
                curr = curr->next;
                prev->next = curr;
            }
        }
    }

    //printing
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    return 0;
}