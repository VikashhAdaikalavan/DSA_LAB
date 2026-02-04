#include <stdio.h>

int countLessEqual(int row[], int C, int x)
{
    int low = 0, high = C - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (row[mid] <= x)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; // number of elements <= x
}

int findMedian(int R, int C,int mat[R][C])
{
    int min = mat[0][0];
    int max = mat[0][C - 1];

    for (int i = 1; i < R; i++)
    {
        if (mat[i][0] < min)
            min = mat[i][0];
        if (mat[i][C - 1] > max)
            max = mat[i][C - 1];
    }

    int required = (R * C) / 2;

    while (min <= max)
    {
        int mid = (min + max) / 2;
        int count = 0;

        for (int i = 0; i < R; i++)
            count += countLessEqual(mat[i], C, mid);

        if (count <= required)
            min = mid + 1;
        else
            max = mid-1;
    }

    return min;
}

int main()
{
    int R, C;
    scanf("%d %d", &R, &C);

    int mat[R][C];
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            scanf("%d", &mat[i][j]);

    printf("%d\n", findMedian(R,C,mat));
    return 0;
}
