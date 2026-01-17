#include <stdio.h>
#include<stdlib.h>

int main()
{
    int arr1[20000];
    int arr2[20000];
    for(int i = 0 ; i< 20000; i++) 
    {arr1[i] = 0;arr2[i] = 0;}
    int n;
    scanf("%d",&n);
    int A[n], B[n+2];
    for(int i = 0; i<n ; i++) 
    {
        scanf("%d", &A[i]);
        arr1[A[i] + 10000]++;
    }
    for(int i = 0 ; i< n+2 ; i++) 
    {
        scanf("%d", &B[i]);
        arr2[B[i] + 10000]++;
    }
    for(int i =0 ; i< 20000 ; i++)
    {
        if(arr1[i] != arr2[i]) printf("%d ",i-10000);
    }
    printf("\n");
    return 0;

}