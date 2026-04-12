//note
#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(char *s, int l, int r, int k) {
    if (r - l + 1 < k) return 0;

    int freq[26] = {0};

    // Count frequency
    for (int i = l; i <= r; i++) {
        freq[s[i] - 'a']++;
    }

    // Check for invalid characters
    for (int i = l; i <= r; i++) {
        if (freq[s[i] - 'a'] < k) {
            int j = i;
            
            // skip all consecutive invalid chars
            while (j <= r && freq[s[j] - 'a'] < k) j++;
            
            // divide into two parts
            int left = solve(s, l, i - 1, k);
            int right = solve(s, j, r, k);
            
            return max(left, right);
        }
    }

    // all characters valid
    return r - l + 1;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    char s[100005];
    scanf("%s", s);

    int ans = solve(s, 0, n - 1, k);
    printf("%d\n", ans);

    return 0;
}