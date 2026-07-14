#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll NEG = -(1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<ll> A(N), B(N), D(N);

    ll base = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        base += A[i];
        D[i] = B[i] - A[i];
    }

    vector<ll> dp0(K + 1, NEG), dp1(K + 1, NEG);
    dp0[0] = 0;

    for (int i = 0; i < N; i++) {
        vector<ll> ndp0(K + 1, NEG), ndp1(K + 1, NEG);

        for (int j = 0; j <= K; j++) {

            ndp0[j] = max(ndp0[j], dp0[j]);

            ndp0[j] = max(ndp0[j], dp1[j]);

            if (dp1[j] != NEG)
                ndp1[j] = max(ndp1[j], dp1[j] + D[i]);

            if (j < K && dp0[j] != NEG)
                ndp1[j + 1] = max(ndp1[j + 1], dp0[j] + D[i]);
        }

        dp0.swap(ndp0);
        dp1.swap(ndp1);
    }

    ll ans = 0;
    for (int j = 0; j <= K; j++) {
        ans = max(ans, dp0[j]);
        ans = max(ans, dp1[j]);
    }

    cout << base + ans << '\n';
    return 0;
}