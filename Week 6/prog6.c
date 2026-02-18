#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);
    
    int n = strlen(s);
    int stack[1000];
    int top = -1;
    
    int maxLen = 0;
    
    // Push -1 initially
    stack[++top] = -1;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;  // pop
            
            if(top == -1) {
                stack[++top] = i;
            } else {
                int len = i - stack[top];
                if(len > maxLen)
                    maxLen = len;
            }
        }
    }
    
    printf("%d\n", maxLen);
    return 0;
}
