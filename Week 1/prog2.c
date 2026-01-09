#include <stdio.h>

void multiplyMatrices(int A[][10], int B[][10], int C[][10], int R1, int C1, int R2, int C2) {
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < C1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int R1, C1, R2, C2;

    
    scanf("%d %d", &R1, &C1);
    int A[10][10];
    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    scanf("%d %d", &R2, &C2);
    int B[10][10];
    for (int i = 0; i < R2; i++) {
        for (int j = 0; j < C2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    if (C1 != R2) {
        printf("Not Possible");
        return 0;
    }

    int C[10][10];
    multiplyMatrices(A, B, C, R1, C1, R2, C2);

    for (int i = 0; i < R1; i++) {
        for (int j = 0; j < C2; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
