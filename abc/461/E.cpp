#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, ll val) {
        idx++;
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    ll sum(int idx) {
        if (idx < 0) return 0;
        idx++;
        ll res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> rowTime(N + 1, 0);
    vector<int> colTime(N + 1, 0);

    Fenwick rowBIT(Q + 1), colBIT(Q + 1);

    rowBIT.add(0, N);
    colBIT.add(0, N);

    ll black = 0;

    for (int t = 1; t <= Q; t++) {
        int type, x;
        cin >> type >> x;

        if (type == 1) {
            int old = rowTime[x];

            black -= colBIT.sum(old - 1);

            rowBIT.add(old, -1);

            rowTime[x] = t;

            rowBIT.add(t, +1);

            black += colBIT.sum(t - 1);
        } else {
            
            int old = colTime[x];

            ll oldBlack = N - rowBIT.sum(old);

            colBIT.add(old, -1);

            colTime[x] = t;

            colBIT.add(t, +1);

            ll newBlack = N - rowBIT.sum(t);

            black += (newBlack - oldBlack);
        }

        cout << black << "\n";
    }

    return 0;
}