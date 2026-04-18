#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxi(int a , int b)
{
    return a> b? a : b;
}

typedef struct 
{
    int x , h;
}Node;

Node* merge(Node* left, int n1, Node* right , int n2, int * size)
{
    int i = 0; int j = 0;int k = 0;
    int h1 = 0; int h2 = 0; int x;
    Node* temp = (Node*)malloc((n1+n2)*sizeof(Node));
    while(i<n1 && j<n2)
    {
        if(left[i].x<right[j].x)
        {
            h1 = left[i].h;
            x = left[i].x;
            i++;
        }
        else
        {
            h2 = right[j].h;
            x = right[j].x;
            j++;
        }
        int maxh = h2>h1?h2:h1;
        if(k == 0|| temp[k-1].h != maxh)
        {
            temp[k++] = (Node){x, maxh};
        }
    }
    while (i<n1)
    {
        if(k == 0|| temp[k-1].h != left[i].h)
        {
            temp[k++] = left[i];
        }
        i++;
    }
    while (j<n2)
    {
        if(k == 0|| temp[k-1].h != right[j].h)
        {
            temp[k++] = right[j];
        }
        j++;
    }
    *size = k;
    return temp;
}

Node* msort(int buildings[][3], int i , int j, int *size)
{
    if(i == j)
    {
        Node* new = (Node*)malloc(2*sizeof(Node));
        new[0] = (Node){buildings[i][0],buildings[i][2]};
        new[1] = (Node){buildings[i][1],0};
        *size = 2;
        return new;
    }

    int mid = (i+j)/2;
    int n1, n2;
    Node* left = msort(buildings,i,mid,&n1);
    Node* right = msort(buildings,mid+1,j,&n2);
    return merge(left,n1,right,n2,size);
}

int main()
{
    int n;
    int size;
    scanf("%d",&n);
    int buildings[n][3];
    for(int i =0; i<n ; i++)
    {
        scanf("%d %d %d", &buildings[i][0], &buildings[i][1], &buildings[i][2]);
    }
    Node* ans = msort(buildings,0,n-1,&size);
    for(int i =0; i< size ; i++)
    {
        printf("%d %d ", ans[i].x, ans[i].h);
    }
    return 0;
}




