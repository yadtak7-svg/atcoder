#include <bits/stdc++.h>
using namespace std;
using ll = long long;

static const ll MOD = 998244353;

ll modpow(ll a, ll e) {
    ll r = 1;
    while (e) {
        if (e & 1) r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, C, D;
    cin >> A >> B >> C >> D;

    int N = A + B + C + D + 5;

    vector<ll> fact(N), ifact(N);
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % MOD;
    }

    ifact[N - 1] = modpow(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; i--) {
        ifact[i] = ifact[i + 1] * (i + 1) % MOD;
    }

    auto Cmb = [&](ll n, ll r) -> ll {
        if (r < 0 || r > n) return 0;
        return fact[n] * ifact[r] % MOD * ifact[n - r] % MOD;
    };

    ll ans = 0;

    for (ll i = 0; i <= C; i++) {
        ll left = Cmb(A + B + i, B);
        ll right = Cmb(D - 1 + C - i, D - 1);
        ans = (ans + left * right) % MOD;
    }

    cout << ans << "\n";

    return 0;
}