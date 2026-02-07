#include<stdio.h>
#include <stdlib.h>

int maxi(int a , int b) 
{
    return a>b? a: b;
}

int sort(int arr[][2], int n)
{
    for(int i = 0 ; i< n-1; i++)
    {
        for(int j = 0; j< n-i-1; j++)
        {
            if(arr[j][0]>arr[j+1][0])
            {
                int temp0 = arr[j][0];
                int temp1 = arr[j][1];
                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j+1][0] = temp0;
                arr[j+1][1] = temp1;
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    if(n == 0) return 0;
    int arr[n][2];
    for(int i = 0; i< n; i++)
    {
        scanf("%d",&arr[i][0]);
        scanf("%d",&arr[i][1]);
    }
    printf("\n");
    sort(arr,n);
    int beg = arr[0][0];
    int end = arr[0][1];

    for(int i = 1 ; i<= n ; i++)
    {
        if( i != n && arr[i][0] <= end)
        {
            end = maxi(arr[i][1],end);
        }
        else
        {
            printf("%d %d\n",beg, end);
            if(i != n)
            {
                beg = arr[i][0];
                end = arr[i][1];
            }
        }
    }
    printf("\n");
    return 0;
}