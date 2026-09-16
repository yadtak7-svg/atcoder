#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> A(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> A[i];
    }

    vector<ll> P(n + 1), Q(n + 1);

    ll lower = 0;
    ll upper = (1LL << 60);

    for (int i = n; i >= 1; i--) {

        P[i] = 1;
        Q[i] = -A[i];

        for (int j = 2 * i; j <= n; j += i) {
            P[i] -= P[j];
            Q[i] -= Q[j];
        }

        if (P[i] > 0) {
            ll need = (-Q[i] + P[i] - 1) / P[i];
            lower = max(lower, need);
        }
        else if (P[i] < 0) {
            ll limit = Q[i] / (-P[i]);
            upper = min(upper, limit);
        }
        else {
            if (Q[i] < 0) {
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    if (lower > upper) {
        cout << -1 << '\n';
        return 0;
    }

    cout << lower - A[1] << '\n';

    return 0;
}