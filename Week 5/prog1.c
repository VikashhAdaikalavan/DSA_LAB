#include <stdio.h>
#include<stdlib.h>

int main()
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);
    int A[m + 1][n + 1];
    int P[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
        for (int j = 0; j <= n; j++)
            P[i][j] = 0;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);

    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            P[i][j] = A[i][j]
                    + P[i - 1][j]
                    + P[i][j - 1]
                    - P[i - 1][j - 1];
        }
    }
    printf("\n");
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
            printf("%d ", P[i][j]);
        printf("\n");
    }

    int sum =
        P[a2][b2]
      - P[a1 - 1][b2]
      - P[a2][b1 - 1]
      + P[a1 - 1][b1 - 1];

    printf("Sum = %d\n", sum);

    return 0;
}
