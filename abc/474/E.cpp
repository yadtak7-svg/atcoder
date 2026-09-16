#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<long long> A(n), B(n), D(n), sumD(n + 1);

        long long MIN = 1e18;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> A[i] >> B[i];

            D[i] = A[i] - B[i];
            MIN = min(MIN, A[i]);
            sum += A[i];
        }

        sort(D.begin(), D.end());

        sumD[0] = 0;
        for (int i = 0; i < n; i++) {
            sumD[i + 1] = sumD[i] + D[i];
        }

        long long ans = 1e18;

        for (int k = 0; k <= n; k++) {
            long long x = sumD[n] - sumD[n - k];

            long long y = max(0LL, 2LL * k - n);

            long long tmp = sum - x + MIN * y;

            ans = min(ans, tmp);
        }

        cout << ans << '\n';
    }
}