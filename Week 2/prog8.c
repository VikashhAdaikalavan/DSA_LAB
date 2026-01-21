#include <stdio.h>
#include<stdlib.h>

int compare(const void * a, const void * b )
{
    return (*((int* )a) - *((int* )b));
}

int main()
{
    int arr1[200000];
    int arr2[200000];
    for(int i = 0 ; i< 200000; i++) 
    {arr1[i] = 0;arr2[i] = 0;}
    int n;
    scanf("%d",&n);
    int A[n], B[n+2];
    for(int i = 0; i<n ; i++) 
    {
        scanf("%d", &A[i]);
        arr1[A[i] + 100000]++;
    }
    for(int i = 0 ; i< n+2 ; i++) 
    {
        scanf("%d", &B[i]);
        arr2[B[i] + 100000]++;
    }
    qsort(A, n, sizeof(int), compare);
    qsort(B, n+2, sizeof(int), compare);

    int pa = 0, pb = 0;

    while (pa < n && pb < n+2)
    {
        if (A[pa] == B[pb])
        {
            pa++;
            pb++;
        }
        else
        {
            printf("%d ", B[pb]);
            pb++;
        }
    }

    while (pb < n+2)
    {
        printf("%d ", B[pb]);
        pb++;
    }

    printf("\n");
    return 0;

}