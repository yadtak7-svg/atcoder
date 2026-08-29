#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);

    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        sum += A[i];
    }

    int cur = 0;
    int ans = 1e9;
    for(int i = 0; i < n; i++) {
        cur += A[i];
        ans = min(ans, abs(cur - (sum - cur)));
    }

    cout << ans << '\n';
}