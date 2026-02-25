#include <stdio.h>

#define MAX 100000

int main() {
    int n;
    scanf("%d", &n);

    int time[MAX], dir[MAX];
    for (int i = 0; i < n; i++) scanf("%d", &time[i]);
    for (int i = 0; i < n; i++) scanf("%d", &dir[i]);

    int enterQ[MAX], exitQ[MAX];
    int ef = 0, eb = -1;
    int xf = 0, xb = -1;

    int ans[MAX];

    int t = 0;
    int i = 0;
    int lastDir = -1; // -1 = idle

    while (i < n || ef <= eb || xf <= xb) {

        //  if nobody waiting, jump time forward
        if (ef > eb && xf > xb && t < time[i]) {
            t = time[i];
            lastDir = -1; // idle
        }

        // add all arrivals at time t
        while (i < n && time[i] <= t) {
            if (dir[i] == 0)
                enterQ[++eb] = i;
            else
                exitQ[++xb] = i;
            i++;
        }

        int used = -1;

        // choose direction
        if (ef <= eb && xf <= xb) {
            // both present
            if (lastDir == -1)
                used = 1;          // idle rule - exit
            else
                used = lastDir;    // momentum rule
        }
        else if (xf <= xb) used = 1;
        else if (ef <= eb) used = 0;

        // process chosen person
        if (used == 1) {
            int p = exitQ[xf++];
            ans[p] = t;
        } else if (used == 0) {
            int p = enterQ[ef++];
            ans[p] = t;
        }

        if (used != -1) {
            lastDir = used;
            t++;
        }
    }

    // print answer
    for (int j = 0; j < n; j++)
        printf("%d ", ans[j]);
    printf("\n");

    return 0;
}