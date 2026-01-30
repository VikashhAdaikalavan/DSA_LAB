#include <stdio.h>
#include <stdlib.h>

//returns -1 if not found
void searchMatrix(int M, int N, int mat[M][N], int K) {
    int i = 0, j = N - 1;

    while (i < M && j >= 0) {
        if (mat[i][j] == K) {
            printf("%d, %d\n", i, j);
            return;
        } else if (mat[i][j] > K) {
            j--;
        } else {
            i++;
        }
    }

    printf("-1\n");
}

int main ()
{
    int n,m;
    scanf("%d",&m);
    scanf("%d",&n);

    int arr[m][n];

    for(int i = 0; i< m; i++)
        for(int j = 0; j<n ; j++)
            scanf("%d",&arr[i][j]);

    int k;
    scanf("%d",&k);
    searchMatrix(m,n,arr,k);

    return 0;
}