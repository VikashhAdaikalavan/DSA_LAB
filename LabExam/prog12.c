//note
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(char *s, int start, int end, int k) {
    if (end - start < k) return 0;

    int freq[26] = {0};
    
    // Count frequency
    for (int i = start; i < end; i++) {
        freq[s[i] - 'a']++;
    }

    // Check for invalid characters
    for (int mid = start; mid < end; mid++) {
        if (freq[s[mid] - 'a'] < k) {
            int midNext = mid + 1;
            
            // Skip consecutive invalid chars
            while (midNext < end && freq[s[midNext] - 'a'] < k) {
                midNext++;
            }

            // Divide into two parts
            return max(
                solve(s, start, mid, k),
                solve(s, midNext, end, k)
            );
        }
    }

    // Entire substring is valid
    return end - start;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[100005];
    scanf("%s", s);

    printf("%d\n", solve(s, 0, n, k));
    return 0;
}