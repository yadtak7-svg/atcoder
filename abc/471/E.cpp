#include <bits/stdc++.h>
using namespace std;

const long long MOD = 998244353;

long long modpow(long long a, long long b) {
    long long res = 1;

    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<long long> fact(n + 1), invfact(n + 1);

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    invfact[n] = modpow(fact[n], MOD - 2);

    for (int i = n; i >= 1; i--) {
        invfact[i - 1] = invfact[i] * i % MOD;
    }

    auto cmb = [&](int n, int k) -> long long {
        if (k < 0 || k > n) return 0;
        return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
    };

    vector<long long> A(n);

    long long sum = 0;
    long long sq_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> A[i];

        sum = (sum + A[i]) % MOD;
        sq_sum = (sq_sum + A[i] * A[i]) % MOD;
    }

    long long c1 = cmb(n - 2, k - 2);
    long long c2 = cmb(n - 1, k - 1);

    long long ans = c1 * sum % MOD * sum % MOD;

    ans += (c2 - c1 + MOD) % MOD * sq_sum % MOD;
    ans %= MOD;

    cout << ans << '\n';
}