#include <stdio.h>
#include <stdlib.h>

int func(int i, int j, int n, char s[n+1])
{
    if(i>j) return 0;
    if(i == j) return 1;
    if(j-i+1 == 3)
    {
        int n1 = s[i] - '0';
        int n2 = s[j] - '0';
        if(s[i+1] =='+' ) return 1;
        else if(s[i+1] == '-') return 1;
        else if(s[i+1] == '*') return 1;
        else return 0;
    }

    int ways = 0;

    for(int k =i ; k <= j ; k++)
    {
        if(s[k] == '*')
        {
            ways += (func(i,k-1,n,s)* func(k+1,j,n,s));
        }
        else if (s[k] == '+') 
        {
            ways += func(i,k-1,n,s)* func(k+1,j,n,s);
        }
        else if(s[k] == '-') 
        {
            ways += func(i,k-1,n,s)* func(k+1,j,n,s);
        }
        
    }
    return ways;
}

int main()
{
    int n;
    scanf("%d",&n);
    char s[n+1];
    scanf("%s",s);
    int arr[n+1][n+1];
    printf("%d\n",func(0,n-1,n,s));
    return 0;
}