#include <stdio.h>
#include <stdlib.h>

typedef struct {
    long long arr[1000];
    int size;
} List;

List func(int i, int j, char s[])
{
    List res;
    res.size = 0;

    // Base case: single digit
    if (i == j)
    {
        res.arr[res.size++] = s[i] - '0';
        return res;
    }

    for (int k = i; k <= j; k++)
    {
        if (s[k] == '+' || s[k] == '-' || s[k] == '*')
        {
            List left = func(i, k - 1, s);
            List right = func(k + 1, j, s);

            for (int a = 0; a < left.size; a++)
            {
                for (int b = 0; b < right.size; b++)
                {
                    long long val;

                    if (s[k] == '+')
                        val = left.arr[a] + right.arr[b];
                    else if (s[k] == '-')
                        val = left.arr[a] - right.arr[b];
                    else
                        val = left.arr[a] * right.arr[b];

                    res.arr[res.size++] = val;
                }
            }
        }
    }

    return res;
}

// Comparator for sorting
int cmp(const void *a, const void *b)
{
    long long x = *(long long *)a;
    long long y = *(long long *)b;
    return (x > y) - (x < y);
}

int main()
{
    int n;
    scanf("%d", &n);

    char s[n + 1];
    scanf("%s", s);

    List ans = func(0, n - 1, s);

    // Sort results
    qsort(ans.arr, ans.size, sizeof(long long), cmp);

    // Print
    for (int i = 0; i < ans.size; i++)
    {
        printf("%lld ", ans.arr[i]);
    }

    printf("\n");
    return 0;
}