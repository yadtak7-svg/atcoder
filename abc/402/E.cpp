#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x;
    cin >> n >> x;

    vector<int> S(n), C(n), P(n);
    for(int i = 0; i < n; i++) {
        cin >> S[i] >> C[i] >> P[i];
    }

    vector<vector<double>> dp(1 << n, vector<double>(x + 1, 0.0));

    for (int mask = (1<<n)-1; mask >= 0; mask--) {
        for (int money = 0; money <= x; money++) {

            for (int i = 0; i < n; i++) {
                if (mask & (1<<i)) continue;     
                if (C[i] > money) continue;     

                double p = P[i] / 100.0;

                dp[mask][money] = max(dp[mask][money],
                    p * (S[i] + dp[mask | (1<<i)][money - C[i]])
                + (1 - p) * dp[mask][money - C[i]]
                );
            }
        }
    }

    cout << fixed << setprecision(10) << dp[0][x] << endl;
}