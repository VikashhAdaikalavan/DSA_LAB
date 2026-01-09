#include<stdio.h>
# include <stdlib.h>


int main()
{
    int n1, n2;
    scanf("%d", &n1);
    int arr1[n1];
    for(int i =0; i< n1; i++)
    {
        scanf("%d",&arr1[i]);
    }
    scanf("%d",&n2);
    int arr2[n2];
    for(int i =0; i< n2; i++)
    {
        scanf("%d",&arr2[i]);
    }

    int ans[n2+n1];
    int i =0;
    int p1 = 0; 
    int p2 = 0;
       while (p1 < n1 && p2 < n2) {
        if (arr1[p1] <= arr2[p2]) {
            ans[i++] = arr1[p1++];
        } else {
            ans[i++] = arr2[p2++];
        }
    }

    while(p1<n1)
    {
        ans[i] = arr1[p1];
        p1++;
        i++;
    }
    while(p2<n2)
    {
        ans[i] = arr2[p2];
        p2++;
        i++;
    }
    for(int j = 0 ; j < n1+n2; j++)
    {
        printf("%d ", ans[j]);
    }
    return 0;

}