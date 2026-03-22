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
    scanf("%d", &n);

    int arr[10000];   
    int heapsize = 0;

    int visited[100001] = {0};  

    heapsize++;
    insert(arr, 2, heapsize);
    visited[2] = 1;

    heapsize++;
    insert(arr, 5, heapsize);
    visited[5] = 1;

    heapsize++;
    insert(arr, 7, heapsize);
    visited[7] = 1;

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        // extract min
        int x = arr[0];
        ans = x;

        arr[0] = arr[heapsize - 1];
        heapsize--;
        heapify(arr, 0, heapsize);

        int a = x * 2;
        int b = x * 5;
        int c = x * 7;

        if(a <= 100000 && !visited[a])
        {
            heapsize++;
            insert(arr, a, heapsize);
            visited[a] = 1;
        }

        if(b <= 100000 && !visited[b])
        {
            heapsize++;
            insert(arr, b, heapsize);
            visited[b] = 1;
        }

        if(c <= 100000 && !visited[c])
        {
            heapsize++;
            insert(arr, c, heapsize);
            visited[c] = 1;
        }
    }

    printf("%d\n", ans);
    return 0;
}