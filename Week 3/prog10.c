#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int maxi(int a , int b) 
{
    return a>b?a:b;
}
int mini(int a , int b) 
{
    return a<b?a:b;
}

double median(int n1,int a[],int n2, int b[]) {
    // Ensure a is the smaller array 
    if (n1 > n2) return median(n2,b, n1,a);
    if(n1 == 0 && n2 == 0) return 0;

    int low = 0, high = n1;

    // Binary search on the smaller array
    while (low <= high) {
        // Calculate the cut positions for both arrays
        int cut1 = (low + high) / 2;
        int cut2 = (n1 + n2 + 1) / 2 - cut1;

        // Handle boundary elements using INT_MIN and INT_MAX
        int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
        int r1 = (cut1 == n1) ? INT_MAX : a[cut1];
        int r2 = (cut2 == n2) ? INT_MAX : b[cut2];

        // If correct partition is found
        if (l1 <= r2 && l2 <= r1) {
            // Total even average of max left and min right
            if ((n1 + n2) % 2 == 0)
                return (maxi(l1, l2) + mini(r1, r2)) / 2.0;
            else
                // Total odd max of left half
                return maxi(l1, l2);
        }
        else if (l1 > r2) {
            // Shift left in a
            high = cut1 - 1;
        }
        else {
            // Shift right in a
            low = cut1 + 1;
        }
    }

    return 0.0;
}

int main() {
    
    int n1,n2;
    scanf("%d",&n1);
    int a[n1];
    for(int i = 0; i < n1 ; i++) scanf("%d",&a[i]);
    scanf("%d",&n2);
    int b[n2];
    for(int i = 0; i< n2 ; i++) scanf("%d",&b[i]);

    printf("%.2f\n",median(n1,a,n2,b));

    return 0;
}
