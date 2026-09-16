#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const long long MOD = 998244353;

    int n; cin >> n;
    string T; cin >> T;

    vector<long long> dp((1 << n), 0);
    dp[(1 << n) - 1] = 1;
    for(int i = (1 << n) - 1; i >= 0; i--) {
        dp[i] %= MOD;
        char pre = '?';
        for(int j  = 0; j < n; j++) {
            if((i >> j) & 1) {
                if(pre != T[j]) {
                    dp[i ^ (1 << j)] += dp[i];
                }
                pre = T[j];
            }
        }
    }

    cout << dp[0] << '\n';
}