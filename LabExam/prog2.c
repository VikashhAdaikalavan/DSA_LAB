#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxi(int a , int b)
{
    return a>b?a:b;
}

int func(int i, int hn , int n ,int h,int maxhrs, int payment[n], int hours[n], int dp[n+1][maxhrs+1])
{
    if(i>=n) return 0;
    if(dp[i][hn] != -1) return dp[i][hn];
    int take = 0;
    if(hn+hours[i]<=h)  take = payment[i] + func(i+1,hn+hours[i],n,h,maxhrs,payment,hours,dp);
    int nottake = 0 + func(i+1,hn,n,h,maxhrs,payment,hours,dp);
    dp[i][hn] = maxi(take, nottake);
    return dp[i][hn];
}


int main()
{
    int n, h;
    scanf("%d %d", &n, &h);
    int payment[n], hours[n];
    int maxhrs = 0;
    for(int i =0 ; i< n ; i++) 
    {
        scanf("%d",&payment[i]);
    }
    for(int i =0; i< n ; i++) 
    {
        scanf("%d",&hours[i]);
        maxhrs+= hours[i];
    }
    int dp[n+1][maxhrs+1];
    for(int i =0; i< n+1; i++)
    {
        for(int j = 0; j<= maxhrs; j++)
        {
            dp[i][j] = -1;
        }
    }

    printf("%d\n",func(0,0,n,h,maxhrs,payment,hours,dp));
    return 0;
}