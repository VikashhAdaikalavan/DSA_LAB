#include <stdio.h>
#include <stdlib.h>

//returns -1 if not found
int search(int n1, int arr[],int k)
{
    int l = 0 ;
    int r = n1-1;

    while(l<=r)
    {
        int mid = (l+r)/2;

        if(arr[mid] == k) return mid;
        if(arr[mid]<=k) l = mid+1;
        else r = mid-1;
    }
    if(arr[r] == k) return r;
    else return -1;

}

int main ()
{
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);

    int arr[m][n];

    for(int i = 0; i< m; i++)
        for(int j = 0; j<n ; j++)
            scanf("%d",&arr[i][j]);
    
    int k;
    scanf("%d",&k);

    for(int i = 0; i< m; i++)
    {
        if(arr[i][0]<=k && arr[i][n-1]>=k) 
        {
            int p2 = search(n,arr[i],k);
            if(p2 != -1)
            {
                printf("%d %d\n",i,p2);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}