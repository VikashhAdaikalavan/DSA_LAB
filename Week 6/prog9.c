#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int stack[n];
    int top = -1;

    int left[n], right[n];

    // Previous Smaller Element
    for(int i = 0; i < n; i++) {
        while(top != -1 && arr[stack[top]] > arr[i])
            top--;
        
        if(top == -1)
            left[i] = i + 1;
        else
            left[i] = i - stack[top];
        
        stack[++top] = i;
    }

    // Reset stack
    top = -1;

    // Next Smaller Element
    for(int i = n - 1; i >= 0; i--) {
        while(top != -1 && arr[stack[top]] >= arr[i])
            top--;
        
        if(top == -1)
            right[i] = n - i;
        else
            right[i] = stack[top] - i;
        
        stack[++top] = i;
    }

    long long sum = 0;

    for(int i = 0; i < n; i++) {
        sum += (long long)arr[i] * left[i] * right[i];
    }

    printf("%lld\n", sum);
    return 0;
}
