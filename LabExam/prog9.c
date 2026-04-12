#include <stdio.h>
#include <stdlib.h>

int mini(int a , int b)
{
    return a<b?a:b;
}

int func(int i, int j, int na,int nb,char seqa[na], char seqb[nb], int dp[na+1][nb+1])
{
    if(j == nb) return na-i ;
    if(i == na) return nb-j;
    if(dp[i][j] != -1) return dp[i][j];
    if(seqa[i] == seqb[j])
    {
        dp[i][j] = func(i+1, j+1, na, nb,seqa,seqb,dp);
    }
    else
    {
        int insert = 1 + func(i,j+1,na,nb,seqa,seqb,dp);
        int delete = 1+ func(i+1,j,na,nb,seqa,seqb,dp);
        int replace = 1 + func(i+1,j+1,na,nb,seqa,seqb,dp);
        dp[i][j] = mini(insert,mini(delete,replace));
    }
    return dp[i][j];
}

int main()
{
    int na, nb;
    scanf("%d %d",&na,&nb);
    char seqa[na+1],seqb[nb+1];
    int dp[na+1][nb+1];
    for(int i =0; i<= na ; i++)
        for(int j = 0; j<= nb ; j++) dp[i][j] = -1;

    scanf("%s",seqa);
    scanf("%s",seqb);
    printf("%d\n",func(0,0,na,nb,seqa,seqb,dp));

    return 0;
}