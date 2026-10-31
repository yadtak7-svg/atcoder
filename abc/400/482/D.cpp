#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> X(n);
    for(int i = 0; i < n; i++) cin >> X[i];

    if(n == 1) {
        cout << 0 << '\n';
        return 0;
    }

    for(int k = 0; k < n; k++) {
        long long ans = 1e9;

        if(k > 0) {
            ans = min(ans, max(X[k] - X[0], X[n - 1] - X[k - 1]) / 2);
        }

        if(k + 1 < n) {
            ans = min(ans, max(X[k + 1] - X[0], X[n - 1] - X[k]) / 2);
        }

        cout << ans << '\n';
    }
}