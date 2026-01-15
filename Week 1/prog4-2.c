#include<stdio.h>
#include<stdlib.h>

int main ()
{
    int n1, n2;
    int arr[10000];
    for(int i = 0; i<10000 ; i++) arr[i] = 0;
    scanf("%d", &n1);
    int A[n1];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &A[i]);
        arr[A[i]]++;
    }

    scanf("%d", &n2);
    int B[n2];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &B[i]);
        arr[B[i]]++;
    }
    printf("Union\n");
    for(int i = 0 ; i< 10000 ; i++ )
    {
        if(arr[i] != 0) printf("%d ",i);
    }
    printf("\n");
    printf("Intersection\n");
    for(int i = 0 ; i< 10000 ; i++ )
    {
        if(arr[i] == 2) printf("%d ",i);
    }
    printf("\n");
    
    
}