#include <stdio.h>

void findUnion(int A[], int n1, int B[], int n2) {
    int i, j, found;

    printf("Union: ");

    for (i = 0; i < n1; i++) {
        printf("%d ", A[i]);
    }

    for (i = 0; i < n2; i++) {
        found = 0;
        for (j = 0; j < n1; j++) {
            if (B[i] == A[j]) {
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("%d ", B[i]);
        }
    }
    printf("\n");
}

void findIntersection(int A[], int n1, int B[], int n2) {
    int i, j;

    printf("Intersection: ");

    for (i = 0; i < n1; i++) {
        for (j = 0; j < n2; j++) {
            if (A[i] == B[j]) {
                printf("%d ", A[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int n1, n2;
    int A[100], B[100];

    scanf("%d", &n1);
    for (int i = 0; i < n1; i++) {
        scanf("%d", &A[i]);
    }

    scanf("%d", &n2);
    for (int i = 0; i < n2; i++) {
        scanf("%d", &B[i]);
    }

    findUnion(A, n1, B, n2);
    findIntersection(A, n1, B, n2);

    return 0;
}
