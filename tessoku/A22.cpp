#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> dp(n + 1, -1), A(n), B(n);
    for(int i = 1; i < n; i++) cin >> A[i];
    for(int i = 1; i < n; i++) cin >> B[i];
    
    dp[1] = 0;
    for(int i = 1; i < n; i++) {
        if(dp[i] == -1) continue;
        dp[A[i]] = max(dp[A[i]], dp[i] + 100);
        dp[B[i]] = max(dp[B[i]], dp[i] + 150);
    }

    cout << dp[n] << endl;
}