#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll count_subtree(ll x, ll d, ll n) {
    ll L = x, R = x;

    while (d--) {
        L *= 2;
        R = R * 2 + 1;

        if (L > n) return 0;
    }

    return max(0LL, min(n, R) - L + 1);
}

ll solve(ll x, ll k, ll n) {
    ll ans = count_subtree(x, k, n);

    ll p = x;

    for (ll i = 1; i <= k; i++) {
        ll child = p;
        p /= 2;

        if (p == 0) break;

        if (i == k) ans++;

        if (i < k) {
            ll sibling = (child % 2 == 0 ? child + 1 : child - 1);
            ans += count_subtree(sibling, k - i - 1, n);
        }
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        long long n, x, k; cin >> n >> x >> k;
        cout << solve(x, k, n) << '\n';
    }

}