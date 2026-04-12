#include <stdio.h>
#include <stdlib.h>

int func(int i, int j, int n, int m , char s[n+1] , char p[m+1])
{
    if(i == n && j == m) return 1;
    if(j == m) return 0;
    if(i == n)
    {
        while(j < m)
        {
            if(p[j] != '*') return 0;
            j++;
        }
        return 1;
    }
    if(s[i] == p[j])
    {
        return func(i+1, j+1, n, m, s, p);
    }
    else
    {
        if(p[j] == '*')
        {
            return func(i+1,j+1,n,m,s,p) || func(i+1,j,n,m,s,p) || func(i,j+1,n,m,s,p);
        }
        else if(p[j] == '?')
        {
            return func(i+1,j+1,n,m,s,p);
        }
        else
        {
            return 0;
        }
    }

}

int main()
{
    int n, m;
    scanf("%d %d",&n,&m);
    char s[n+1], p[m+1];
    scanf("%s",s);
    scanf("%s",p);
    int ans = func(0,0,n,m,s,p);
    if(ans) printf("YES\n");
    else printf("NO\n");
    return 0;
}