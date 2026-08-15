#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, L;
    cin >> N >> M >> L;

    vector<int> A(N);
    for (auto &x : A) cin >> x;

    vector<int> dp(M, INF);
    dp[0] = 0;

    for (int i = 0; i < L; i++) {
        vector<int> cost(M, 0);

        for (int k = i; k < N; k += L) {
            for (int j = 0; j < M; j++) {
                cost[j] += (j - A[k] + M) % M;
            }
        }

        vector<int> ndp(M, INF);

        for (int r = 0; r < M; r++) {
            if (dp[r] == INF) continue;

            for (int j = 0; j < M; j++) {
                int nr = (r + j) % M;

                ndp[nr] = min(ndp[nr], dp[r] + cost[j]);
            }
        }

        dp = move(ndp);
    }

    cout << dp[0] << '\n';
}