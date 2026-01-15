#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    char s[100];
    char ans[100];
    fgets(s, sizeof(s), stdin);
    int l = 0;
    int r = 0;
    int i = 0;
    int len = strlen(s);
    if(len == 0) return 0;
     while (r < len) {
        if (r < len && s[l] == s[r]) {
            r++;
        } else {
            ans[i++] = s[l];
            i += sprintf(&ans[i], "%d", r - l);
            l = r;
        }
    }
    // ans[i++] = s[l];
    // i += sprintf(&ans[i], "%d", r - l);
    // l = r;
    ans[i] = '\0';
    if (strlen(ans) < strlen(s))
        printf("%s", ans);
    else
        printf("%s", s);

    return 0;

}