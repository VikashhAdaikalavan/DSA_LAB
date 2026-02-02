#include <stdio.h>
#include<stdlib.h>

int merge(int arr[][2], int temp[][2], int left, int mid, int right)
{
    int i = left;
    int j = mid+1;
    int k = left;

    while(i<= mid && j<=right)
    {
        if(arr[i][0]>arr[j][0])
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

int main()
{
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);
    int arr[n][2];
    for(int i= 0; i< n ; i++) 
    {
        scanf("%d",&arr[i][0]);
        arr[i][1] = i;
    }
    sort(arr,n);

    int l = 0;
    int r = 0;
    int found = 0;
    while(r <= n)
    {
        if( r == n || arr[r][0] != arr[l][0])
        {
            if(arr[r-1][1] - arr[l][1] > k)
            {
                printf("%d %d\n",arr[l][1],arr[r-1][1]);
                found = 1;
                break;
            }
            l = r;
        }
        r++;
    }

    if(found == 0) printf("-1\n");
    for(int i= 0; i< n ; i++) printf("(%d %d) ",arr[i][0], arr[i][1]);
    printf("\n");
    return 0;
}

