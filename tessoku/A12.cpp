#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; long long k; cin >> n >> k;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    long long l = 0, r = 1e9 + 1;
    while(l <= r) {
        long long mid = (l + r) / 2;
        long long ans = 0;
        for(long long x : A) ans += mid / x;
        if(ans < k) l = mid + 1;
        else r = mid - 1; 
    }

    cout << l << '\n';
}