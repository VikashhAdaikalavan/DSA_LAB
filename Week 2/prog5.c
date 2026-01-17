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

    if(n == 0) return 0;
    if(n == 1)
    {
        printf("%d", head->val);
        return 0;
    }
    node* l = head;
    node* r = l->next;
    prev = NULL;
    head = r;
    while(r != NULL)
    {
        l->next = r->next;
        r->next = l;
        if(prev == NULL) prev = l;
        else
        {
            prev->next = r;
            prev = l;
        }
        l = l->next;
        if(l == NULL) r = NULL;
        else r = l->next;
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