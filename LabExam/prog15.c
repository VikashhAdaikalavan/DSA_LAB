//note
#include <stdio.h>

typedef long long ll;

typedef struct {
    ll sum, prefix, suffix, best;
    ll sum_sq, prefix_sq, suffix_sq, best_sq;
} Node;

ll max(ll a, ll b) { return a > b ? a : b; }

Node make_node(ll x) {
    Node n;

    n.sum = x;
    n.prefix = n.suffix = n.best = x;

    ll sq = x * x;
    n.sum_sq = sq;
    n.prefix_sq = n.suffix_sq = n.best_sq = sq;

    return n;
}

Node merge(Node L, Node R) {
    Node res;

    // normal
    res.sum = L.sum + R.sum;

    res.prefix = max(L.prefix, L.sum + R.prefix);
    res.suffix = max(R.suffix, R.sum + L.suffix);

    res.best = max(
        max(L.best, R.best),
        L.suffix + R.prefix
    );

    // with square
    res.sum_sq = max(L.sum_sq + R.sum, L.sum + R.sum_sq);

    res.prefix_sq = max(
        max(L.prefix_sq, L.sum_sq + R.prefix),
        L.sum + R.prefix_sq
    );

    res.suffix_sq = max(
        max(R.suffix_sq, R.sum_sq + L.suffix),
        R.sum + L.suffix_sq
    );

    res.best_sq = max(
        max(L.best_sq, R.best_sq),
        max(L.suffix_sq + R.prefix,
            L.suffix + R.prefix_sq)
    );

    return res;
}

Node solve(int l, int r, ll arr[]) {
    if (l == r) return make_node(arr[l]);

    int mid = (l + r) / 2;

    Node left = solve(l, mid, arr);
    Node right = solve(mid + 1, r, arr);

    return merge(left, right);
}

int main() {
    int n;
    scanf("%d", &n);

    ll arr[n];
    for (int i = 0; i < n; i++) scanf("%lld", &arr[i]);

    Node ans = solve(0, n - 1, arr);

    printf("%lld\n", ans.best_sq);

    return 0;
}