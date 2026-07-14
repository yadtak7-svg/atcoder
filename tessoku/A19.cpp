#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, W; cin >> n >> W;
    
    vector<long long> dp(W + 1, -1); dp[0] = 0;
    
    for(int i = 0; i < n; i++) {
        int w; long long v; 
        cin >> w >> v;
        for(int i = W - w; i >= 0; i--) {
            if(dp[i] != -1) dp[i + w] = max(dp[i + w], dp[i] + v);
        }
    }

    long long ans = -1;
    for(long long x : dp) ans = max(ans, x);
    cout << ans << endl;
}