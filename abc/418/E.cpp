#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

ull encode(int x, int y) {
    return (ull)(uint32_t)x << 32 | (uint32_t)y;
}

pair<int, int> normalization(int dx, int dy) {
    int g = gcd(abs(dx), abs(dy));
    dx /= g;
    dy /= g;

    if (dx < 0 || (dx == 0 && dy < 0)) {
        dx = -dx;
        dy = -dy;
    }

    return {dx, dy};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> X(N), Y(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i];
    }

    unordered_map<ull, ll> mp;
    unordered_map<ull, ll> mid;

    mp.reserve((ll)N * (N - 1) / 2);
    mid.reserve((ll)N * (N - 1) / 2);

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {

            int dx = X[i] - X[j];
            int dy = Y[i] - Y[j];

            auto [nx, ny] = normalization(dx, dy);

            mp[encode(nx, ny)]++;

            int sx = X[i] + X[j];
            int sy = Y[i] + Y[j];

            mid[encode(sx, sy)]++;
        }
    }

    ll ans = 0;

    for (auto [key, cnt] : mp) {
        ans += cnt * (cnt - 1) / 2;
    }

    for (auto [key, cnt] : mid) {
        ans -= cnt * (cnt - 1) / 2;
    }

    cout << ans << '\n';
}