#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i< n ; i++)
    {
        scanf("%d",&arr[i]);
    }
    int ans[n];
    int stk[n][2];
    int top = -1;
    for(int i = n-1 ; i>=0; i--)
    {
        while(top!= -1 && stk[top][0]<= arr[i])
        {
            top--;
        }
        if(top == -1) ans[i] = 0;
        else ans[i] = stk[top][1] - i;
        top = top+1;
        stk[top][0] = arr[i];
        stk[top][1] = i;
    }

    for(int i = 0; i< n ; i++) printf("%d ",ans[i]);
    return 0;
}