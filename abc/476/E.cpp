#include <bits/stdc++.h>
using namespace std;

using pii = pair<int,int>;

struct Range {
    pii mn, mx;
};

Range merge(const Range& a, const Range& b) {
    Range res;
    res.mn = min(a.mn, b.mn);
    res.mx = max(a.mx, b.mx);
    return res;
}

struct SegTree {
    int n;
    vector<Range> tree;

    SegTree(const vector<int>& arr) {
        int sz = arr.size();
        n = 1;
        while (n < sz) n <<= 1;

        tree.assign(2 * n, {{INT_MAX, -1}, {INT_MIN, -1}});

        for (int i = 0; i < sz; i++) {
            tree[n + i] = {{arr[i], i}, {arr[i], i}};
        }

        for (int i = n - 1; i >= 1; i--) {
            tree[i] = merge(tree[i << 1], tree[i << 1 | 1]);
        }
    }

    void update(int idx, int val) {
        int pos = idx + n;
        tree[pos] = {{val, idx}, {val, idx}};
        pos >>= 1;

        while (pos >= 1) {
            tree[pos] = merge(tree[pos << 1], tree[pos << 1 | 1]);
            pos >>= 1;
        }
    }

    Range query(int l, int r) {
        l += n;
        r += n;

        Range left = {{INT_MAX, -1}, {INT_MIN, -1}};
        Range right = {{INT_MAX, -1}, {INT_MIN, -1}};

        while (l < r) {
            if (l & 1) left = merge(left, tree[l++]);
            if (r & 1) right = merge(tree[--r], right);
            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    SegTree seg(A);

    while (Q--) {
        int L, R;
        cin >> L >> R;
        L--, R--;

        Range info = seg.query(L, R + 1);

        int idxMin = info.mn.second;
        int idxMax = info.mx.second;

        swap(A[idxMin], A[idxMax]);

        seg.update(idxMin, A[idxMin]);
        seg.update(idxMax, A[idxMax]);
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << (i + 1 == N ? '\n' : ' ');
    }
}
