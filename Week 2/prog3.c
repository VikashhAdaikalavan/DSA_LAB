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
    int k;
    scanf("%d",&k);
    if (n == 0 || k == 0 || k%n == 0) {
        node* temp = head;
        while (temp != NULL) {
            printf("%d ", temp->val);
            temp = temp->next;
        }
        return 0;
    }
    k = k%n;
    prev = NULL;
    node* p1 = head;
    for(int i = 0; i< n-k; i++)
    {
        prev = p1;
        p1 = p1-> next;
    }

    prev->next = NULL;
    prev = p1;
    while(p1->next != NULL) p1 = p1->next;
    p1->next = head;
    head = prev;
    node* temp = head;
    while(temp != NULL)
    {
        printf("%d ",temp->val);
        temp = temp->next;
    }
    return 0;
}