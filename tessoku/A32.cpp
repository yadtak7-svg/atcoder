#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, a, b; cin  >> n >> a >> b;
    vector<bool> dp(n + 1);
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        bool win = false;
        if(i >= a && dp[i-a] == 0) win = true;
        if(i >= b && dp[i-b] == 0) win = true;
        dp[i]=win;
    }

    if(dp[n]) cout << "First\n";
    else cout << "Second\n"; 
}