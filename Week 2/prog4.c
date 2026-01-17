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

    int sum = 0;
    node* p1 = head;
    int i = 0;
    while(p1 != NULL)
    {
        sum = sum + p1->val;
        i++;
        if(i == 2)
        {
            i = 0;
            node* temp = (node*)malloc(sizeof(node));
            temp->val = sum;
            sum = 0;
            temp->next = p1->next;
            p1->next = temp;
            p1 = temp->next;
        }
        else p1 = p1->next;
    }

    if(n%2 == 1)
    {
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        node* newnode = (node*)malloc(sizeof(node));
        newnode->val = temp->val;
        temp->next = newnode;
        newnode->next = NULL;
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