#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    long long p;
    cin >> n >> m >> p;

    vector<long long> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> sumB(m + 1, 0);
    for (int i = 0; i < m; i++) {
        sumB[i + 1] = sumB[i] + B[i];
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long x = p - A[i];

        int cnt = upper_bound(B.begin(), B.end(), x) - B.begin();

        ans += 1LL * cnt * A[i];
        ans += sumB[cnt];

        ans += 1LL * (m - cnt) * p;
    }

    cout << ans << '\n';
    return 0;
}
