#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100];
    fgets(s,sizeof(s),stdin);
    s[strcspn(s,"\n")] = '\0';
    int wc = 1;
    int vc = 0;
    char rev[100];
    int len = strlen(s);
    int j;
    for(int i = 0; i<len ; i++)
    {
        if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ) vc++;
        if(s[i] == ' ') wc++;
        rev[len-i-1] = s[i];
    }
    rev[len] = '\0';

    printf("Words = %d\n",wc);
    printf("Vowels = %d\n",vc);
    printf("Reversed : %s",rev);
    return 0;
}
