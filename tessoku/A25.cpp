#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W; cin >> H >> W;
    vector<vector<long long>> dp(H, vector<long long>(W, 0));
    dp[0][0] = 1;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char c; cin >> c; 
            if(c == '#') continue;
            if(i > 0) dp[i][j] += dp[i - 1][j];
            if(j > 0) dp[i][j] += dp[i][j - 1];
        }
    }
    cout << dp[H - 1][W - 1] << endl;
}