#include<stdio.h>
#include<stdlib.h>

int main()
{

    int n;
    scanf("%d",&n);
    int nums[n];
    if (n == 0) return 0;
    for(int i = 0 ; i< n ; i++)
    {
        scanf("%d",&nums[i]);
    }
    int target;
    scanf("%d",&target);

    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int mid = (left+right)/2;
        if(nums[mid] == target)
        {
            printf("%d\n",mid);
            return 0;
        }

        if(nums[left]<=nums[mid])
        {
            if(nums[left]<=target && target<nums[mid])
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        else
        {
            if(nums[mid]<target && target<=nums[right])
            {
                left = mid+1;
            }
            else 
            {
                right = mid-1;
            }
        }
    }
    printf("-1\n");
    return 0;
}