#include<stdio.h>
#include <stdlib.h>

int finddiv(int n)
{
    int c = 0;
    for(int i =1; i<= n ; i++)
    {
        if(n%i == 0) c++;
    }
    return c;
}

int sort(int arr[][2], int n)
{
    for(int i = 0 ; i< n-1; i++)
    {
        for(int j = 0; j< n-i-1; j++)
        {
            if(arr[j][1]>arr[j+1][1])
            {
                int temp0 = arr[j][0];
                int temp1 = arr[j][1];
                arr[j][0] = arr[j+1][0];
                arr[j][1] = arr[j+1][1];
                arr[j+1][0] = temp0;
                arr[j+1][1] = temp1;
            }
            else if(arr[j][1] == arr[j+1][1] && arr[j][0]<arr[j+1][0])
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
    int arr[n][2];
    for(int i = 0; i< n; i++)
    {
        scanf("%d",&arr[i][0]);
        arr[i][1] = finddiv(arr[i][0]);
    }
    sort(arr,n);

    for(int i =0 ; i< n ; i++)
    {
        printf("%d ", arr[i][0]);
    }

    printf("\n");
    return 0;
}