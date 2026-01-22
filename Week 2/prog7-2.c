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

    node* head1 = NULL;
    node* head2 = NULL;
    node* s1 = NULL;
    node*s2 = NULL;
    node* p = head;

    while(p!= NULL)
    {
        if(p->val == x)
        {
            if(head2 == NULL)
            {
                s2 = p;
                head2 = p;
                p = p->next;
            }
            else
            {
                s2->next = p;
                s2 = p;
                p = p->next;
            }
        }
        else
        {
            if(head1 == NULL)
            {
                s1 = p;
                head1 = p;
                p = p->next;
            }
            else
            {
                s1->next = p;
                s1 = p;
                p = p->next;
            }

        }
    }

    if(s1) s1->next = NULL;
    if (s2) s2->next = NULL;

    if(head1 == NULL)
        head = head2;         
    else
    {
        s1->next = head2;
        head = head1;
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