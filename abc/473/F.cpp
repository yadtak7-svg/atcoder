#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct Node {
    ll sum; 
    ll mn;  
};

Node merge(Node L, Node R) {
    return {
        L.sum + R.sum,
        min(L.mn, L.sum + R.mn)
    };
}

struct SegTree {
    int n;
    vector<Node> seg;

    SegTree(const string& S) {
        int N = S.size();

        n = 1;
        while (n < N) n <<= 1;

        seg.assign(2 * n, {0, 0});

        for (int i = 0; i < N; i++) {
            ll x = (S[i] == 'A' ? 1 : -1);
            seg[n + i] = {x, x};
        }

        for (int i = n - 1; i >= 1; i--) {
            seg[i] = merge(seg[2 * i], seg[2 * i + 1]);
        }
    }

    void update(int pos, char c) {
        int k = n + pos;

        ll x = (c == 'A' ? 1 : -1);
        seg[k] = {x, x};

        k >>= 1;

        while (k >= 1) {
            seg[k] = merge(seg[2 * k], seg[2 * k + 1]);
            k >>= 1;
        }
    }

    Node query(int l, int r) {
        Node left = {0, 0};
        Node right = {0, 0};

        l += n;
        r += n;

        while (l < r) {
            if (l & 1) {
                left = merge(left, seg[l]);
                l++;
            }

            if (r & 1) {
                --r;
                right = merge(seg[r], right);
            }

            l >>= 1;
            r >>= 1;
        }

        return merge(left, right);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    string S;
    cin >> S;

    SegTree st(S);

    int q;
    cin >> q;

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int i;
            char c;
            cin >> i >> c;

            i--;

            S[i] = c;
            st.update(i, c);
        }
        else {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            Node res = st.query(l, r + 1);

            if (res.mn >= 0) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }

    return 0;
}