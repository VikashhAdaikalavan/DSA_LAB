#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int h[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &h[i]);

    int stack[n];
    int top = -1;
    int maxArea = 0;

    for(int i = 0; i <= n; i++)
    {
        int currHeight = (i == n) ? 0 : h[i];

        while(top != -1 && h[stack[top]] > currHeight)
        {
            int height = h[stack[top--]];

            int right = i;
            int left = (top == -1) ? -1 : stack[top];

            int width = right - left - 1;
            int area = height * width;

            if(area > maxArea)
                maxArea = area;
        }

        stack[++top] = i;
    }

    printf("%d", maxArea);
    return 0;
}
