#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    long long x, y; cin >> x >> y; 
    vector<long long> P(n - 1), T(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> P[i] >> T[i];

    long long dp[840];
    for(int k = 0; k < 840; k++) {
        long long a = k + x;
        for(int i = 0; i < n - 1; i++) {
            a += (P[i] - a % P[i]) % P[i];
            a += T[i];
        }
        a += y;
        dp[k] = a;
    }

    int q; cin >> q;
    while(q--) {
        long long t; cin >> t;
        cout << t / 840 * 840 + dp[t % 840] << '\n';
    }
}