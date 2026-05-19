#include <bits/stdc++.h>
#include <atcoder/modint>
using namespace std;
using namespace atcoder;

using ll = long long;
using mint = atcoder::modint998244353;

const long long MOD = 998244353;
int x1, x2, x3;

vector<mint> frac, invf;
void f_init (const ll n) {
	frac.resize(n+1);
	invf.resize(n+1);
	frac[0] = 1;
	for (ll i = 1; i <= n; i++) {
		frac[i] = frac[i-1] * i;
	}
	invf[n] = frac[n].inv();
	for (ll i = n; i >= 1; i--) {
		invf[i-1] = invf[i] * i;
	}
}
mint ncr (ll n, ll r) {
	if (n < 0 || n < r) return 0;
	return frac[n] * invf[r] * invf[n-r];
}
mint part1 (ll x, ll p) {
	return ncr(x-1, p-1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> x1 >> x2 >> x3;

    f_init(x1 + x2 + x3 + 10);

    mint ans = 0;

    for(ll i = 2; i <= x1; i++) {
        ans += part1(x1, i) * part1(x3, i - 1) * ncr(x1 + x2 + x3 - (i * 2 - 2), x1 + x3);
    }

    for(ll i = 2; i <= x3; i++) {
        ans += part1(x3, i) * part1(x1, i - 1) * ncr(x1 + x2 + x3 - (i * 2 - 2), x1 + x3);
    }

    for(ll i = 1; i <= min(x1, x3); i++) {
        ans += 2 * part1(x1, i) * part1(x3, i) * ncr(x1 + x2 + x3 - (i * 2 - 1), x1 + x3);
    }

    cout << ans.val() << endl;
}