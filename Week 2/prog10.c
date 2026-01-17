#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int k;
    scanf("%d",&k);
    for(int i =0 ; i<n ; i++)
    scanf("%d", &arr[i]);
    
    qsort(arr,n,sizeof(int),compare);

    int l = 0; 
    int r = 0;
    int ans = 0;
    for(int r = 0; r< n ; r++)
    {
        if(arr[r] - arr[l]<=k)
        {
            ans = ans>r-l+1?ans: r-l+1;
        }
        else
        {
            while(l<=r && arr[r] - arr[l]>k) l++;
            ans = ans>r-l+1?ans: r-l+1;
        }
    }
    printf("%d\n",ans);

    return 0;

}