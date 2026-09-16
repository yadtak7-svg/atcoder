#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;
    vector<long long> A(n);
    for(int i = 0; i < n; i++) cin >> A[i];
    
    int head = 0;
    vector<long long> sum(n); sum[0] = A[0];
    for(int i = 1; i < n; i++) sum[i] = sum[i - 1] + A[i];
    while(q--) {
        int t; cin >> t;

        if(t == 1) {
            int c; cin >> c;
            head = (head + c) % n;            
        }

        if(t == 2) {
            int l, r; cin >> l >> r; l--, r--;
            l = (l + head) % n, r = (r + head) % n;
            
            long long ans = 0;
            if(l <= r) {
                ans = sum[r] - (l == 0 ? 0 : sum[l - 1]);
            } else {
                ans = (sum[n - 1] - (l == 0 ? 0 : sum[l - 1])) + sum[r];
            }

            cout << ans << '\n';
        }
    }
}