# include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i =0 ; i<n ; i++)
    scanf("%d", &arr[i]);

    qsort(arr,n,sizeof(int),compare);

    int l = 0; 
    int r = 0;
    if(n == 0) return 0;

    while(r<n)
    {
        if(arr[l] == arr[r]) r++;
        else 
        {
            printf("%d -> %d\n",arr[l], r-l);
            l = r;
        }
    }
    printf("%d -> %d\n",arr[l], r-l);
    l = r;

    return 0;

}