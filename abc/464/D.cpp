#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n;
        string S;
        cin >> n;
        cin >> S;

        vector<long long> X(n), Y(n - 1);
        for(int i = 0; i < n; i++) cin >> X[i];
        for(int i = 0; i < n - 1; i++) cin >> Y[i];

        vector<vector<long long>> dp(n, vector<long long>(2, -INF));
        if(S[0]== 'R') {
            dp[0][0] = 0;
            dp[0][1] = -X[0];
        }
        else {
            dp[0][0] = -X[0];
            dp[0][1] = 0;
        }

        for (int i = 1; i < n; i++) {
            long long cost[2];
            if (S[i] == 'R') {
            cost[0] = 0;
            cost[1] = -X[i];
            } else {
                cost[0] = -X[i];
                cost[1] = 0;
            }

            for (int pre = 0; pre < 2; pre++) {
                for (int cur = 0; cur < 2; cur++) {
                    long long add = cost[cur];

                    if (pre == 0 && cur == 1)
                        add += Y[i - 1];

                    dp[i][cur] = max(dp[i][cur],dp[i - 1][pre] + add);
                }
            }
        }
        cout << max(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
}