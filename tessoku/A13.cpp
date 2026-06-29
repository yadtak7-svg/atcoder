#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    long long n, k; cin >> n >> k;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];

    long long ans = 0;
    long long j = 0;
    for(int i = 0; i < n; i++) {
        while(j < n && A[j] - A[i] <= k) j++;
        ans += (j - i - 1);
    }

    cout << ans << '\n';
}