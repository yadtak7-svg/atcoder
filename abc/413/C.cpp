#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<long long, long long>> A(n + 1);
    int head = 0, last = 0;
    while(n--) {
        int t; cin >> t;
        if(t == 1) {
            long long c, x; cin >> c >> x;
            A[head++] = {x, c};
        }
        if(t == 2) {
            int k; cin >> k;
            long long ans = 0;
            while(k > 0) {
                int used;
                if(k < A[last].second) {
                    ans += A[last].first * k;
                    A[last].second -= k;
                    used = k;
                } 
                else {
                    ans += A[last].first * A[last].second;
                    used = A[last].second;
                    last++;
                }
                k -= used;
            }
            cout << ans << '\n';
        }
    }
}