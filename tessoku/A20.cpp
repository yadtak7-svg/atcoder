#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, T; cin >> T >> S;
    int t = T.size(), s = S.size();
    vector<vector<int>> dp(t + 1, vector<int>(s + 1, 0));

    for(int i = 1; i <= t; i++) {
        for(int j = 1; j <= s; j++) {
            if(T[i - 1] == S[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    cout << dp[t][s] << endl;
 
}