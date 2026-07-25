#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<long long> D(n - 1), A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end());
    long long ans = 0;
    for(int i = 0; i < n - 1; i++) {
        D[i] = abs(A[i] - A[i + 1]);
    }
    sort(D.begin(), D.end());
    for(int i = 0; i < n - m; i++) {
        ans += D[i];
    }
    cout << ans << '\n';
}