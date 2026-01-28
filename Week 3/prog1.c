#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b)
{
    const int* row1 = (const int *)a;
    const int* row2 = (const int *)b;

    if(row1[0] == row2[0])
    {
        return row1[1] - row2[1]; 
    }
    else
    {
        return row2[0] - row1[0];
    }
}


int main()
{
    int t;
    scanf("%d",&t);
    if (t == 0) return 0;
    int arr[t][2];

    for(int i = 0 ; i< t ; i++)
    {
        scanf("%d",&arr[i][0]);
        scanf("%d",&arr[i][1]);
    }

    qsort(arr,t,sizeof(arr[0]),compare);
    printf("\n");
    for (int i = 0; i < t; i++) printf("%d %d\n", arr[i][0], arr[i][1]);
    printf("\n");

    return 0;
}