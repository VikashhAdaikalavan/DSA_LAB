#include <stdio.h>
#include <limits.h>

int min(int a, int b, int arr[])
{
    return arr[a]>arr[b]?b:a;
}
int parent(int i,int n)
{
    if(i == 0) return -1;
    else return (i-1)/2;
}
int lchild(int i,int n)
{
    return 2*i+1;
}

int rchild(int i,int n)
{
    return 2*i+2;
}

void heapify(int *arr, int i, int hs)
{
    if(i>=hs) return;
    int smallest =i;
    int r = i;
    int lc = lchild(i,hs);
    int rc = rchild(i,hs);
    if(lc <hs) smallest = min(r,lc,arr);
    if(rc <hs) smallest = min(smallest,rc,arr);
    if(smallest != i)
    {
        int temp = arr[smallest];
        arr[smallest] = arr[i];
        arr[i] = temp;
        heapify(arr,smallest,hs);
    }
    return;
}

void insert(int *arr ,int val,int hs)
{
    arr[hs-1] = val;
    int i = (hs) -1;
    int par = parent(i,hs);
    while(par != -1 && arr[par]>arr[i])
    {
        int temp = arr[par];
        arr[par] = arr[i];
        arr[i] = temp;
        i = par;
        par = parent(i,hs);
    }
}

void swap(int ind1, int ind2, int *arr)
{
    int t = arr[ind1];
    arr[ind1] = arr[ind2];
    arr[ind2] = t;
    return;
}

int main()
{
    int n;
    int heapsize = 0;
    scanf("%d",&n);
    int arr[n*n];
    for(int i = 0; i< n*n ; i++) arr[i] = -1;
    for(int i = 0; i< n*n ; i++)
    {
        int no;
        scanf("%d",&no);
        heapsize++;
        insert(arr,no,heapsize);
    }
    for(int i = 0 ; i< n*n ; i++)
    {
        swap(0,heapsize-1,arr);
        heapsize--;
        heapify(arr,0,heapsize);
    }
    heapsize = n*n;
    int k;
    scanf("%d",&k);
    printf("%d\n",arr[n*n - k]);
    return 0;
}