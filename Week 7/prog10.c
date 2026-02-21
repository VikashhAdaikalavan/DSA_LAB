#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int time[MAX], dir[MAX];
    for (int i = 0; i < n; i++) scanf("%d", &time[i]);
    for (int i = 0; i < n; i++) scanf("%d", &dir[i]);

    int ans[MAX];


    int enterQ[MAX], exitQ[MAX];
    int ef = 0, er = 0;  
    int xf = 0, xr = 0; 

    int t = 0;
    int i = 0;
    int last = -1; // -1 idle

    while (i < n || ef < er || xf < xr) {

        if (ef == er && xf == xr && t < time[i]) {
            t = time[i];
            last = -1;
        }

        while (i < n && time[i] <= t) {
            if (dir[i] == 0)
                enterQ[er++] = i;
            else
                exitQ[xr++] = i;
            i++;
        }

        int used = -1;

        if (ef < er && xf == xr) {
            used = 0;
        }
        else if (xf < xr && ef == er) {
            used = 1;
        }
        else if (ef < er && xf < xr) {
            if (last == -1) used = 1;       
            else used = last;               
        }

        if (used == 0) {
            int idx = enterQ[ef++];
            ans[idx] = t;
            last = 0;
            t++;
        }
        else if (used == 1) {
            int idx = exitQ[xf++];
            ans[idx] = t;
            last = 1;
            t++;
        }
    }

    for (int k = 0; k < n; k++)
        printf("%d ", ans[k]);

    return 0;
}
