#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int maxi(int a, int b)
{
    return a>b?a:b;
}
int main()
{
    char str[100];
    scanf("%s",str);
    char stk[100];
    int top = -1;
    int len = 0;
    int maxlen = 0;
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == '(')
        {
            stk[++top] = '(';
        }
        else
        {
            if(top == -1)
            {
                maxlen = maxi(maxlen,len);
                top = -1;
                len = 0;
                continue;
            }
            top--;
            len = len+2;
        }
    }
    maxlen = maxi(maxlen,len);
    printf("%d\n",maxlen);
    return 0;
}