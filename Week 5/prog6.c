#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int mat[N][M];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int layers = (N < M ? N : M) / 2;

    for (int layer = 0; layer < layers; layer++) {
        int top = layer;
        int bottom = N - layer - 1;
        int left = layer;
        int right = M - layer - 1;

        // Skip single row or single column layers
        if (top == bottom || left == right)
            continue;

        int temp[2 * (bottom - top + right - left)];
        int k = 0;

        // Top row (left -> right)
        for (int j = left; j <= right; j++)
            temp[k++] = mat[top][j];

        // Right column (top+1 -> bottom)
        for (int i = top + 1; i <= bottom; i++)
            temp[k++] = mat[i][right];

        // Bottom row (right-1 -> left)
        for (int j = right - 1; j >= left; j--)
            temp[k++] = mat[bottom][j];

        // Left column (bottom-1 -> top+1)
        for (int i = bottom - 1; i > top; i--)
            temp[k++] = mat[i][left];

        int len = k;

        // Rotate by 1
        if (layer % 2 == 0) {
            // Clockwise (right rotate)
            int last = temp[len - 1];
            for (int i = len - 1; i > 0; i--)
                temp[i] = temp[i - 1];
            temp[0] = last;
        } else {
            // Counter-clockwise (left rotate)
            int first = temp[0];
            for (int i = 0; i < len - 1; i++)
                temp[i] = temp[i + 1];
            temp[len - 1] = first;
        }

        k = 0;

        // Write back

        // Top row
        for (int j = left; j <= right; j++)
            mat[top][j] = temp[k++];

        // Right column
        for (int i = top + 1; i <= bottom; i++)
            mat[i][right] = temp[k++];

        // Bottom row
        for (int j = right - 1; j >= left; j--)
            mat[bottom][j] = temp[k++];

        // Left column
        for (int i = bottom - 1; i > top; i--)
            mat[i][left] = temp[k++];
    }

    printf("\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
