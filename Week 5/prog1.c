#include <stdio.h>

int main()
{
    int M, N;
    scanf("%d", &M);
    scanf("%d", &N);
    int A[M + 1][N + 1];
    int P[M + 1][N + 1];

    for (int i = 0; i <= M; i++)
        for (int j = 0; j <= N; j++)
            P[i][j] = 0;

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            scanf("%d", &A[i][j]);

    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            P[i][j] = A[i][j]
                    + P[i - 1][j]
                    + P[i][j - 1]
                    - P[i - 1][j - 1];
        }
    }
    printf("\n");
    for (int i = 1; i <= M; i++)
    {
        for (int j = 1; j <= N; j++)
            printf("%d ", P[i][j]);
        printf("\n");
    }

    int a1, b1, a2, b2;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);

    int sum =
        P[a2][b2]
      - P[a1 - 1][b2]
      - P[a2][b1 - 1]
      + P[a1 - 1][b1 - 1];

    printf("Sum = %d\n", sum);

    return 0;
}
