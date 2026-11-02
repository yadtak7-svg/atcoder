#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1LL << 60;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, p; cin >> n >> k >> p;
    vector<long long> C(n);
    vector<vector<int>> A(n,vector<int>(k));

    for(int i = 0; i < n; i++) {
        cin >> C[i];
        for(int j = 0; j < k; j++) {
            cin >> A[i][j];
        }
    }

    int S = 1;
    for (int i = 0; i < k; i++) {
        S *= p + 1;
    }

    vector<int> pw(k);
    pw[0] = 1;
    for (int i = 1; i < k; i++) {
        pw[i] = pw[i - 1] * (p + 1);
    }

    vector<ll> dp(S, INF);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        vector<ll> ndp = dp;

        for (int s = 0; s < S; s++) {
            if (dp[s] == INF) continue;

            int t = s;

            for (int j = 0; j < k; j++) {
                int x = (s / pw[j]) % (p + 1);
                int y = min(p, x + A[i][j]);

                t += (y - x) * pw[j];
            }

            ndp[t] = min(ndp[t], dp[s] + C[i]);
        }

        dp = ndp;
    }

    cout << (dp[S - 1] == INF ? -1 : dp[S - 1]) << '\n';
}
