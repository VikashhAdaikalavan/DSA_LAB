#include <stdio.h>
#include <stdlib.h>

typedef struct node{
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
    node* toadd = NULL;
    node* p = head;
    prev = NULL;
    while(p != NULL )
    {
        if(p->val %2 != 0)
        {
            prev = p;
            p = p->next;
        }
        else
        {
            if(prev == NULL)
            {
                prev = p;
                toadd = p;
                p = p->next;
                continue;
            }
            if(toadd == NULL)
            {
                prev->next = p->next;
                p->next = head;
                head = p;
                toadd = head;
                p = prev->next;
            }
            else
            {
                prev->next = p->next;
                p->next = toadd->next;
                toadd->next = p;
                toadd = toadd->next;
                p = prev->next;
            }

        }
    }  

    node * temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    return 0;
}