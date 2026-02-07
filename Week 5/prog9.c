#include <stdio.h>

void sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
            {
                int t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    sort(arr, n);

    int found = 0;

    for(int i = 0; i<n;i++)
    {
        if(i>0 && arr[i] == arr[i-1])
        {
            continue;
        }
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = arr[i]+arr[j]+arr[k];
            if(sum>0)
            {
                k--;
            }
            else if(sum<0)
            {
                j++;
            }
            else
            {
                found = 1;
                printf("%d %d %d\n",arr[i],arr[j],arr[k]);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1])
                {
                    j++;
                }
                while(j<k && arr[k] == arr[k+1])
                {
                    k--;
                }
            }
        }
    }
        

    if(!found)
        printf("No triples found\n");

    return 0;
}
