#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A1(n + 1), A2(n + 1);
    for(int i = 1; i < n; i++) cin >> A1[i];
    for(int i = 2; i < n; i++) cin >> A2[i];

    vector<int> dp(n, 1e9);
    dp[0] = 0; dp[1] = A1[1];
    for(int i = 2; i < n; i++) dp[i] = min(dp[i - 1] + A1[i], dp[i - 2] + A2[i]);

    int cur = n - 1;
    vector<int> ans; ans.push_back(cur);
    while(cur > 0) {
        int s;
        if(cur - 2 >= 0 && dp[cur] - A2[cur] == dp[cur - 2]) s = 2;
        else s = 1;

        ans.push_back(cur - s);
        cur -= s;
    }

    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i] + 1 << ' ';
    cout << endl;
}