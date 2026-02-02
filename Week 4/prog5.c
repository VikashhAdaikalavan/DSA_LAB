#include <stdio.h>
#include<stdlib.h>

int merge(int arr[][2], int temp[][2], int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<= mid && j<=right)
    {
        if(arr[i][1]<arr[j][1])
        {
            temp[k][0] = arr[j][0];
            temp[k++][1] = arr[j++][1];
        }
        else if(arr[i][1] >arr[j][1])
        {
            temp[k][0] = arr[i][0];
            temp[k++][1] = arr[i++][1];
        }
        else
        {
            if(arr[i][0]<arr[j][0])
            {
                temp[k][0] = arr[j][0];
                temp[k++][1] = arr[j++][1];
            }
            else
            {
            temp[k][0] = arr[i][0];
            temp[k++][1] = arr[i++][1];
            }
        }
    }
    while(i<=mid) 
    {
        temp[k][0] = arr[i][0];
        temp[k++][1] = arr[i++][1];
    }
    while(j<=right) 
    {
        temp[k][0] = arr[j][0];
        temp[k++][1] = arr[j++][1];
    }

    for(int i = left ; i<=right ; i++) 
    {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
    }
    return 1;

}

int msort(int arr[][2] , int temp[][2], int left, int right)
{
    if(left>= right) return 0;

    int mid = (left+right)/2;
    msort(arr,temp,left,mid);
    msort(arr,temp,mid+1,right);
    merge(arr,temp,left,mid,right);
    return 1;

}

int sort(int arr[][2], int n)
{
    int temp[n][2];
    msort(arr,temp,0,n-1);
    return 0;
}

int no1(int n)
{
    int ans = 0;
    while(n != 0)
    {
        if(n%2 == 1) ans++;
        n = n/2;
    }
    return ans;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][2];
    for(int i= 0; i< n ; i++) 
    {
        scanf("%d",&arr[i][0]);
        arr[i][1] = no1(arr[i][0]);
    }
    sort(arr,n);
    for(int i= 0; i< n ; i++) printf("%d ",arr[i][0]);
    printf("\n");
    return 0;
}

