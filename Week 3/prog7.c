#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

int compare(const void* a, const void* b)
{
    return *((int*) a) - *((int*) b);
}

void sort(int * arr, int x)
{
    qsort(arr,x,sizeof(int),compare);
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0 ; i< n ; i++) scanf("%d",&arr[i]);

    int end = 0;
    int start = 0;
    int i = 1;
    while(start<n)
    {
        if(end >= n)
            end = n - 1;
        sort(arr+start,end - start+1);
        start = end+1;
        end = start+i;
        i++;
    }
    for (int i = 0 ; i< n ; i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}