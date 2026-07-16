#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b; cin >> a >> b;
    long long cur = a % mod, ans = 1;
    while (b > 0) {
        if (b & 1) 
            ans = ans * cur % mod;
        cur = cur * cur % mod;
        b >>= 1;
        
    }

    cout << ans << endl;

}