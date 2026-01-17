#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node* next;
    
}node;

int main()
{
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

    node * p1 = NULL;
    node * p2 = head;
    prev = NULL;
    
    while(p2 != NULL)
    {
        if(p2->val % 2 == 1) 
        {
            prev = p2;
            p2 = p2->next; 
        }
        else
        {
            prev->next = p2->next;
            if(p1 == NULL)
            {
                p2->next = head;
                head = p2;
                p2 = prev->next;
                p1 = head;
            } 
            else
            {
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2;
                p2 = prev->next;
            }
        }
    }

    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    return 0;
}