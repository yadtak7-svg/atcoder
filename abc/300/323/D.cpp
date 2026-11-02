#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<ll> S(n), C(n);
    map<ll, ll> mp;

    for(int i = 0; i < n; i++) {
        cin >> S[i] >> C[i];
        mp[S[i]] += C[i];
    }

    int ans = 0;
    while(!mp.empty()) {
        auto it = mp.begin();
        ll s = it -> first;
        ll c = it -> second;

        mp.erase(it);
        
        ans += c % 2;
        int k = 1;
        if (c / 2 > 0) {
            mp[2 * s] += c / 2;
        }
    }

    cout << ans << '\n';
}