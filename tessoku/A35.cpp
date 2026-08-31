#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> dp(N);
    for (int &x : dp) cin >> x;

    for (int step = 0; step < N - 1; step++) {
        for (int i = 0; i < N - 1 - step; i++) {
            if (step % 2 == 0) {
                dp[i] = max(dp[i], dp[i + 1]);
            } else {
                dp[i] = min(dp[i], dp[i + 1]);
            }
        }
    }

    cout << dp[0] << '\n';
}