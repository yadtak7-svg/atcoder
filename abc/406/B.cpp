#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    long long lim = 0;
    while(k--) lim = (lim + 1) * 10 - 1;

    long long ans = 1;
    for(int i = 0; i < n; i++) {
        long long m; cin >> m;

        if(lim / ans / m  == 0) {
            ans = 1;
        }
        else ans *= m;
    }

    cout << ans << endl;
}