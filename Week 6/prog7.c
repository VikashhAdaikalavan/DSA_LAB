#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    char s[MAX];
    scanf("%s", s);

    char strStack[MAX][MAX];   
    int countStack[MAX];       

    int top = -1;
    char current[MAX] = "";
    int k = 0;

    for(int i = 0; s[i] != '\0'; i++) {

        if(isdigit(s[i])) {
            k = k * 10 + (s[i] - '0');
        }

        else if(s[i] == '[') {
            top++;
            countStack[top] = k;
            strcpy(strStack[top], current);
            k = 0;
            current[0] = '\0';
        }

        else if(s[i] == ']') {
            char temp[MAX];
            strcpy(temp, current);

            strcpy(current, strStack[top]);
            int repeat = countStack[top--];

            while(repeat--) {
                strcat(current, temp);
            }
        }

        else { 
            int len = strlen(current);
            current[len] = s[i];
            current[len+1] = '\0';
        }
    }

    printf("%s\n", current);
    return 0;
}
