#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long d = 0;
    long long i = 1;
    while (i <= n) {
        long long v = n / i;
        long long j = n / v;
        long long cnt = (j - i + 1) % MOD;
        d = (d + cnt * (v % MOD)) % MOD;
        i = j + 1;
    }

    long long n_mod = n % MOD;
    long long inv2 = (MOD + 1) / 2; 
    long long total = n_mod % MOD * ((n_mod + 1) % MOD) % MOD * inv2 % MOD;

    long long ans = ((total - d) % MOD + MOD) % MOD;

    cout << ans << '\n';
}