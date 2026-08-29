#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<ll> X(n), Y(n);
    for (int i = 0; i < n; i++) {
        cin >> X[i] >> Y[i];
    }

    vector<ll> c(n), x(n), y(n);

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;

        c[i] = X[i] * Y[j] - X[j] * Y[i];

        x[i] = c[i] * (X[i] + X[j]);
        y[i] = c[i] * (Y[i] + Y[j]);
    }

    vector<ll> sumc(2 * n + 1);
    vector<i128> sumx(2 * n + 1);
    vector<i128> sumy(2 * n + 1);

    for (int i = 0; i < 2 * n; i++) {
        int j = i % n;

        sumc[i + 1] = sumc[i] + c[j];
        sumx[i + 1] = sumx[i] + x[j];
        sumy[i + 1] = sumy[i] + y[j];
    }

    auto getC = [&](int l, int r) -> ll {
        return sumc[r] - sumc[l];
    };

    auto getX = [&](int l, int r) -> i128 {
        return sumx[r] - sumx[l];
    };

    auto getY = [&](int l, int r) -> i128 {
        return sumy[r] - sumy[l];
    };

    while (q--) {
        int u, v;
        cin >> u >> v;

        --u;
        --v;

        ll sc = X[u] * Y[v] - X[v] * Y[u];

        i128 sx = (i128)(X[u] + X[v]) * sc;
        i128 sy = (i128)(Y[u] + Y[v]) * sc;

        ll C;
        i128 SX, SY;

        if (u < v) {
            C = getC(u, v);
            SX = getX(u, v);
            SY = getY(u, v);
        } else {
            C = getC(u, v + n);
            SX = getX(u, v + n);
            SY = getY(u, v + n);
        }

        C -= sc;
        SX -= sx;
        SY -= sy;

        long double gx = (long double)SX / (3.0L * C);
        long double gy = (long double)SY / (3.0L * C);

        cout << fixed << setprecision(15)
            << gx << ' ' << gy << '\n';
    }
}