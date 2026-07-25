#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main(){
    int n;
    cin >> n;
    vector<ll> A(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];

    vector<ll> inv(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; i++) {
        inv[i] = (MOD - (MOD/i) * inv[MOD % i] % MOD) % MOD;
    }

    vector<ll> P(n+1, 0);
    for (int i = 1; i <= n; i++) P[i] = (P[i - 1] + A[i]) % MOD;

    vector<ll> Q(n + 2, 0);
    for (int m = 1; m <= n + 1; m++) Q[m] = (Q[m - 1] + P[m - 1]) % MOD;

    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        ll val = ((Q[n + 1] - Q[n - k + 1] - Q[k]) % MOD + 2 * MOD) % MOD;
        ans = (ans + val * inv[k]) % MOD;
    }

    cout << ans << '\n';
}