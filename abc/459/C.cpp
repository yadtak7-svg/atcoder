#include <bits/stdc++.h>
using namespace std;

struct Fenwick {
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        idx++;
        while(idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        idx++;
        int s = 0;
        while(idx > 0) {
            s += bit[idx];
            idx -= idx & -idx;
        }
        return s;
    }

    int rangeSum(int l, int r) {
        if(l > r) return 0;
        return sum(r) - (l ? sum(l - 1) : 0);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> A(N, 0);

    const int MAXV = Q + 5;

    vector<int> freq(MAXV, 0);

    Fenwick bit(MAXV);

    freq[0] = N;
    bit.add(0, N);

    int dh = 0;

    while(Q--) {
        int t, x;
        cin >> t >> x;

        if(t == 1) {
            x--;

            freq[A[x]]--;
            bit.add(A[x], -1);

            A[x]++;

            freq[A[x]]++;
            bit.add(A[x], 1);

            if(freq[dh] == 0) {
                dh++;
            }
        }
        else {
            int y = x;

            int threshold = y + dh;

            int ans = bit.rangeSum(threshold, MAXV - 1);

            cout << ans << '\n';
        }
    }
}