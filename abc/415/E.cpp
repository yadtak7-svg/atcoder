#include <bits/stdc++.h>
using namespace std;
const long long NEG = LLONG_MIN / 2;

int H, W;
vector<vector<long long>> A;
vector<long long> Pd; 
bool check(long long x) {
    vector<vector<long long>> dp(H, vector<long long>(W, NEG));

    
    long long init = x + A[0][0] - Pd[0];
    dp[0][0] = (init >= 0) ? init : NEG;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i == 0 && j == 0) continue;
            long long best = NEG;
            if (i > 0 && dp[i-1][j] > NEG) best = max(best, dp[i-1][j]);
            if (j > 0 && dp[i][j-1] > NEG) best = max(best, dp[i][j-1]);
            if (best == NEG) continue;

            long long val = best + A[i][j] - Pd[i + j];
            dp[i][j] = (val >= 0) ? val : NEG;
        }
    }

    return dp[H-1][W-1] > NEG;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> H >> W;
    A.assign(H, vector<long long>(W));
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> A[i][j];

    Pd.assign(H + W - 1, 0);
    for (int t = 0; t < H + W - 1; t++) cin >> Pd[t];

    long long l = 0, r = (long long)4e15;
    while (l < r) {
        long long mid = l + (r - l) / 2;
        if (check(mid)) r = mid;   
        else l = mid + 1;          
    }
    cout << l << endl;
}