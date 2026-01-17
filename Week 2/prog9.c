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

    int ec = 0;
    int oc = 0;
    for(int i =0; i< n ; i++)
    {
        if(arr[i] % 2 == 0 && i%2 == 0) ec++;
        if(arr[i] % 2 == 1 && i%2 == 1) oc++;
    }
    printf("%d %d \n",ec,oc);

    return 0;

}