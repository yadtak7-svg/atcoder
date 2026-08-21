#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool onLine(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
    __int128 dx1 = (__int128)x2 - x1;
    __int128 dy1 = (__int128)y2 - y1;

    __int128 dx2 = (__int128)x3 - x1;
    __int128 dy2 = (__int128)y3 - y1;

    return dx1 * dy2 == dy1 * dx2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<ll> X(n), Y(n);
    for(int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist(0, n - 1);

    for(int t = 0; t < 100; t++) {
        int a = dist(rng);
        int b = dist(rng);

        while(a == b) {
            b = dist(rng);
        }

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            if(onLine(X[a], Y[a], X[b], Y[b], X[i], Y[i])) {
                cnt++;
            }
        }

        if(2 * cnt > n) {
            ll A = Y[b] - Y[a];
            ll B = X[a] - X[b];
            ll C = -(A * X[a] + B * Y[a]);

            cout << "Yes\n";
            cout << A << " " << B << " " << C << '\n';
            return 0;
        }
    }

    cout << "No\n";
}