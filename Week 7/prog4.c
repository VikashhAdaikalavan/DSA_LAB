#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n;
    scanf("%d %d", &m, &n);
    int arr[m][n];
    int vis[m][n];
    for(int i = 0; i<m; i++)
    {
        for(int j = 0; j< n ; j++)
        {
            vis[i][j] = 0;
        }
    }
    for(int i = 0 ; i< m; i++)
    {
        for(int j = 0; j<n ; j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    int q[10000][2];
    int front = 0;
    int back = 0;
    q[0][0] = 0;
    q[0][1] = 0;
    int p = 0;
    while(front<=back)
    {
        p++;
        int c = back-front+1;
        for(int i = 0; i< c ; i++)
        {
            int x = q[front][0];
            int y = q[front++][1];
            if(vis[x][y] == 1) continue;
            vis[x][y] = 1;
            if(arr[x][y] == 2)
            {
                printf("%d\n",p);
                return 0;
            }
            if(x + 1<m && arr[x+1][y] != 1) 
            {
                q[++back][0] = x+1;
                q[back][1] = y;
            }
            if(x - 1>=0 && arr[x-1][y] != 1) 
            {
                q[++back][0] = x-1;
                q[back][1] = y;
            }
            if(y + 1<n && arr[x][y+1] != 1) 
            {
                q[++back][0] = x;
                q[back][1] = y+1;
            }
            if(y-1>=0 && arr[x][y-1] != 1) 
            {
                q[++back][0] = x;
                q[back][1] = y-1;
            }
        }

    }
    printf("No path found\n");
    return 0;
}