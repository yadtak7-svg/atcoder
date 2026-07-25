#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> P(n);
    for (int i = 0; i < n; i++) cin >> P[i];

    int ans = 0;
    vector<int> cur = P;

    for (int t = 0; t < 2 && !cur.empty(); t++) {
        int m = cur.size();

        vector<int> dp;
        vector<int> pos;
        vector<int> pre(m, -1);

        for (int i = 0; i < m; i++) {
            int j = lower_bound(dp.begin(), dp.end(), cur[i]) - dp.begin();

            if (j == (int)dp.size()) {
                dp.push_back(cur[i]);
                pos.push_back(i);
            } else {
                dp[j] = cur[i];
                pos[j] = i;
            }

            if (j > 0) pre[i] = pos[j - 1];
        }

        ans += dp.size();
        vector<bool> used(m, false);
        int x = pos.back();
        while (x != -1) {
            used[x] = true;
            x = pre[x];
        }
        vector<int> nxt;
        for (int i = 0; i < m; i++) {
            if (!used[i]) nxt.push_back(cur[i]);
        }

        cur = move(nxt);
    }

    cout << ans << '\n';

    return 0;
}