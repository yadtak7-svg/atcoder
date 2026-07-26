#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        long long m;
        cin >> n >> m;

        vector<long long> A(n), B(n);
        for (int i = 0; i < n; i++) cin >> A[i];
        for (int i = 0; i < n; i++) cin >> B[i];

        sort(A.begin(), A.end(), greater<long long>()); 
        sort(B.begin(), B.end());                       

        long long c = 0;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            long long v = A[i];
            while (idx < n && B[idx] + v < m) idx++;
            if (idx >= n) break;
            c++;
            idx++;
        }

        long long ans = accumulate(A.begin(), A.end(), 0LL)
                      + accumulate(B.begin(), B.end(), 0LL)
                      - m * c;
        cout << ans << "\n";
    }
}