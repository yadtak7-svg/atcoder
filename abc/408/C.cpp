#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> sum(n + 1, 0);
    for(int i = 0; i < m; i++) {
        int l, r; cin >> l >> r; l--, r--;
        sum[l]++; sum[r + 1]--;
    }

    int ans = sum[0];
    for(int i = 1; i < n; i++) {
        sum[i] += sum[i - 1];
        ans = min(ans, sum[i]);
    }

    cout << ans << endl;
}