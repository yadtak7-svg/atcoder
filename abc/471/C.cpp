#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> A(n);
    for (auto &x : A) cin >> x;

    sort(A.begin(), A.end());

    int l = lower_bound(A.begin(), A.end(), 0LL) - A.begin() - 1;
    int r = l + 1;

    long long cur = 0;
    long long ans = 0;

    while (l >= 0 || r < n) {
        if (l < 0) {
            ans += abs(cur - A[r]);
            cur = A[r];
            r++;
        }
        else if (r >= n) {
            ans += abs(cur - A[l]);
            cur = A[l];
            l--;
        }
        else if (abs(cur - A[l]) <= abs(cur - A[r])) {
            ans += abs(cur - A[l]);
            cur = A[l];
            l--;
        }
        else {
            ans += abs(cur - A[r]);
            cur = A[r];
            r++;
        }
    }

    cout << ans << '\n';
}