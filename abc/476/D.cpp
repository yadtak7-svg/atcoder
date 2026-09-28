#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    long long k;
    cin >> n >> m >> k;

    long long x, y;
    cin >> x >> y;

    vector<long long> A(n), B(m);

    for (int i = 0; i < n; i++) cin >> A[i];
    for (int i = 0; i < m; i++) cin >> B[i];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<long long> sumA(n + 1, 0);
    vector<long long> sumB(m + 1, 0);

    vector<long long> prefB(m + 1, 0);

    for (int i = 0; i < n; i++) {
        sumA[i + 1] = sumA[i] + A[i];
    }

    for (int i = 0; i < m; i++) {
        sumB[i + 1] = sumB[i] + B[i];

        prefB[i + 1] = prefB[i] + (B[i] + k - 1) / k;
    }

    int ans = 0;

    for (int i = 0; i <= m; i++) {

        if (prefB[i] > y) continue;

        long long lim = x + k * y - sumB[i];

        if (lim < 0) continue;

        int cnt = upper_bound(sumA.begin(), sumA.end(), lim) - sumA.begin() - 1;

        ans = max(ans, i + cnt);
    }

    cout << ans << '\n';

    return 0;
}