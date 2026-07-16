#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> P(n + 1), A(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> P[i] >> A[i];
    }

    const int NEG = -1e9;
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, NEG));

    dp[1][n] = 0;

    for (int l = 1; l <= n; l++) {
        for (int r = n; r >= l; r--) {
            if (dp[l][r] == NEG) continue;

            if (l < n) {
                int score = 0;
                if (l + 1 <= P[l] && P[l] <= r)
                    score = A[l];
                dp[l + 1][r] = max(dp[l + 1][r], dp[l][r] + score);
            }

            if (r > 1) {
                int score = 0;
                if (l <= P[r] && P[r] <= r - 1)
                    score = A[r];
                dp[l][r - 1] = max(dp[l][r - 1], dp[l][r] + score);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[i][i]);
    }

    cout << ans << '\n';
    return 0;
}