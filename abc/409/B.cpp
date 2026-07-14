#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];

    sort(A.begin(), A.end());

    int l = 0, r = n; 
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = n - (lower_bound(A.begin(), A.end(), mid) - A.begin());
        if (cnt >= mid) {
            ans = mid;   
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << "\n";
}
