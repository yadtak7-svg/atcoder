#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<int> P(n), invP(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
        --P[i];
        invP[P[i]] = i;
    }

    while (q--) {
        int t;
        cin >> t;

        if (t == 1) {
            int x, y;
            cin >> x >> y;
            --x;
            --y;

            int a = P[x];
            int b = P[y];

            swap(P[x], P[y]);

            invP[a] = y;
            invP[b] = x;
        } else {
            swap(P, invP);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << P[i] + 1 << (i + 1 == n ? '\n' : ' ');
    }
}