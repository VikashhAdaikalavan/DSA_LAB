//note
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, h;
} Point;

// merge two skylines (like merge in merge sort)
Point* merge(Point* left, int n1, Point* right, int n2, int* size)
{
    int i = 0, j = 0, k = 0;
    int h1 = 0, h2 = 0;

    Point* temp = (Point*)malloc((n1 + n2) * sizeof(Point));

    while (i < n1 && j < n2)
    {
        int x;

        if (left[i].x < right[j].x)
        {
            x = left[i].x;
            h1 = left[i].h;
            i++;
        }
        else
        {
            x = right[j].x;
            h2 = right[j].h;
            j++;
        }

        int maxh = h1 > h2 ? h1 : h2;

        if (k == 0 || temp[k-1].h != maxh)
            temp[k++] = (Point){x, maxh};
    }

    // remaining (same like your merge)
    while (i < n1)
    {
        if (k == 0 || temp[k-1].h != left[i].h)
            temp[k++] = left[i];
        i++;
    }

    while (j < n2)
    {
        if (k == 0 || temp[k-1].h != right[j].h)
            temp[k++] = right[j];
        j++;
    }

    *size = k;
    return temp;
}

// divide like msort
Point* msort(int buildings[][3], int left, int right, int* size)
{
    if (left == right)
    {
        Point* res = (Point*)malloc(2 * sizeof(Point));

        res[0] = (Point){buildings[left][0], buildings[left][2]};
        res[1] = (Point){buildings[left][1], 0};

        *size = 2;
        return res;
    }

    int mid = (left + right) / 2;

    int n1, n2;

    Point* leftSky = msort(buildings, left, mid, &n1);
    Point* rightSky = msort(buildings, mid + 1, right, &n2);

    return merge(leftSky, n1, rightSky, n2, size);
}

int main()
{
    int n;
    scanf("%d", &n);

    int buildings[n][3];

    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &buildings[i][0], &buildings[i][1], &buildings[i][2]);

    int size;
    Point* res = msort(buildings, 0, n - 1, &size);

    for (int i = 0; i < size; i++)
        printf("%d %d ", res[i].x, res[i].h);

    return 0;
}