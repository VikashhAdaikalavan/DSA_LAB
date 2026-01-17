#include <stdio.h>
#include <stdlib.h>


typedef struct node {
    int val;
    struct node* next;
    
}node;

node* reverse(node * start)
{
    node* curr = start;
    node* after = NULL;
    node* prev = NULL;
    while(curr != NULL)
    {
        after = curr->next;
        curr->next = prev;
        prev = curr;
        curr = after;
    }
    return prev;
}


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
    
    node* fast = head;
    node* slow = head;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    node* p2 = reverse(slow);
    node* p1 = head;

    while(p2 != NULL && p1 != NULL)
    {
        if(p2->val != p1->val) 
        {
            printf("False\n");
            return 0;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    printf("True\n");

    return 0;
}

