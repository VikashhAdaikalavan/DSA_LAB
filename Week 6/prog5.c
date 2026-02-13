#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[100];
    scanf("%s",str);
    float stk[100];
    int top = -1;
    int i = 0; 
    while(str[i] != '\0')
    {
        if(str[i]>='0' && str[i]<='9') stk[++top] = str[i] - '0';
        else
        {
            int n2 = stk[top--];
            int n1 = stk [top--];
            char c = str[i];
            if(c == '+') 
            {
                stk[++top] = (n1 + n2);
            }
            else if(c == '-'){
                stk[++top] = (n1 - n2);
            }
            else if(c == '*') {
                stk[++top] = (n1 * n2);
            }
            else {
                stk[++top] = ((float)n1 / n2);
            }
        }
        i++;
    }

    printf("%.2f\n",stk[top]);
    return 0;
}