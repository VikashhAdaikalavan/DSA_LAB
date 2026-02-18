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
            if(top == -1) 
            {
                printf("Invalid Sequence\n");
                return 0;
            }
            float n2 = stk[top--];
            if(top == -1) 
            {
                printf("Invalid Sequence\n");
                return 0;
            }
            float n1 = stk [top--];
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
            else if (c == '/'){
                if(n2 == 0) 
                {
                    printf("Invalid expression\n");
                    return 0;
                }
                stk[++top] = ((float)n1 / n2);
            }
            else
            {
                printf("Invalid expression\n");
                    return 0;
            }
        }
        i++;
    }

    if(top != 0) 
    {
        printf("Invalid expression\n");
        return 0;
    }
    printf("%.2f\n",stk[top]);
    return 0;
}