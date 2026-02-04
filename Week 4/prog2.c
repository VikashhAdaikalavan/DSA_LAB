#include <stdio.h>
#include<stdlib.h>

// int merge(int arr[], int temp[], int left, int mid, int right)
// {
//     int i = left;
//     int j = mid+1;
//     int k = left;

//     while(i<= mid && j<=right)
//     {
//         if(arr[i]>arr[j])
//         {
//             temp[k++] = arr[j++];
//         }
//         else temp[k++] = arr[i++];
//     }
//     while(i<=mid) temp[k++] = arr[i++];
//     while(j<=right) temp[k++] = arr[j++];

//     for(int i = left ; i<=right ; i++) arr[i] = temp[i];
//     return 1;

// }

// int msort(int arr[] , int temp[], int left, int right)
// {
//     if(left>= right) return 0;

//     int mid = (left+right)/2;
//     msort(arr,temp,left,mid);
//     msort(arr,temp,mid+1,right);
//     merge(arr,temp,left,mid,right);
//     return 1;

// }

// int mssort(int arr[], int n)
// {
//     int temp[n];
//     msort(arr,temp,0,n-1);
//     return 0;
// }

void sort(int arr[],int n)
{
    for(int i = 0; i< n-1 ; i++)
    {
        for(int j = 0; j< n-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp; 
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i= 0; i< n ; i++) scanf("%d",&arr[i]);
    int l = 0;
    int r = n-1;
    int k = 1;

    while(l<r)
    {
        if(k%2 != 0)
        {
            if(r-l+1 <k)
            {
                k = r-l+1;
                sort(arr + l , k);
                break;
            } 
            sort(arr + l , k);
            l = l +k;
            k++;
        }
        else
        {
            if(r-l+1 <k)
            {
                k = r-l+1;
                sort(arr + r -k +1,k);
                break;
            }
            sort(arr + r -k +1,k);
            r = r -k;
            k++;
        }

    }
    for(int i= 0; i< n ; i++) printf("%d ",arr[i]);
    printf("\n");
    return 0;
}

