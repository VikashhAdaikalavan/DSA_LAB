#include <stdio.h>
#include <stdlib.h>

int main ()
{
    int freq[27];
    for(int i = 0; i< 26; i++) freq[i] = 0;
    int q[1000];
    int front = 0;
    int back = -1;
    char str[100];
    scanf("%s",str);
    for(int i = 0; str[i] != '\0'; i++)
    {
        freq[str[i]-'0']++;
        q[++back] = str[i];
        while(front <= back && freq[q[front]-'0']>1)
        {
            front++;
        }
        if(front <=back) printf("%c ",q[front]);
        else printf("%d ",-1);

    }

    return 0;
}