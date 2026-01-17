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

    while(curr != tail->next)
    {
        if(curr->val == x)
        {
            if(prev == NULL)
            {
                head = curr->next;
                last->next = curr;
                curr = curr->next;
                last = last->next;
                last->next = NULL;
            }
            else
            {
                prev->next = curr->next;
                last ->next = curr;
                curr->next = NULL;
                last = last->next;
                curr = prev->next;
            }

        }
        else
        {
            prev = curr;
            curr = curr->next;
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