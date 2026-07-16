#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> dp((1 << n), -1); dp[0] = 0;
    vector<int> C(m, 0);
    for(int i = 0; i < m; i++) { 
        for(int j = 0; j < n; j++) {
            C[i] *= 2;
            int x; cin >> x;
            if(x) C[i]++;
        }
    }

    for(int i = 0; i < m; i++) {
        vector<int> ndp = dp;
        for(int j = 0; j < (1 << n); j++) {
            if(dp[j] == -1) continue;
            if(ndp[j | C[i]] == -1) ndp[j | C[i]] = dp[j] + 1;
            ndp[j | C[i]] = min(ndp[j | C[i]], dp[j] + 1);
        }
        dp = ndp;
    }

    cout << dp[(1 << n) - 1] << endl;
}