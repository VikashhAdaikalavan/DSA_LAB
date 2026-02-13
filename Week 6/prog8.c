#include <stdio.h>

int isPossible(int n, int seq1[], int seq2[])
{
    int stk[n];
    int top = -1;
    int j = 0;

    for(int i = 0; i < n; i++)
    {
        stk[++top] = seq1[i];

        while(top != -1 && j < n && stk[top] == seq2[j])
        {
            top--;
            j++;
        }
    }

    return (j == n);
}

int main()
{
    int n;
    scanf("%d", &n);

    int seq1[n];
    int seq2[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &seq1[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &seq2[i]);


    if(!isPossible(n, seq1, seq2))
    {
        printf("Impossible\n");
        return 0;
    }

    
    int stk[n];
    int top = -1;
    int j = 0;

    for(int i = 0; i < n; i++)
    {
        stk[++top] = seq1[i];
        printf("Push\n");

        while(top != -1 && j < n && stk[top] == seq2[j])
        {
            top--;
            j++;
            printf("Pop\n");
        }
    }

    return 0;
}
