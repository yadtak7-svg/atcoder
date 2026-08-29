#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    ll K;
    cin >> N >> K;

    vector<ll> P(N + 1);

    for (int i = 1; i <= N; i++) {
        ll A;
        cin >> A;
        P[i] = (P[i - 1] + A) % K;
    }

    vector<ll> v = P;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    vector<int> id(N + 1);

    for (int i = 0; i <= N; i++) {
        id[i] = lower_bound(v.begin(), v.end(), P[i])
                - v.begin();
    }

    vector<int> seen(v.size(), 0);

    int version = 1;
    int ans = 0;

    seen[id[0]] = version;

    for (int i = 1; i <= N; i++) {
        if (seen[id[i]] == version) {
            ans++;

            version++;
            seen[id[i]] = version;
        } else {
            seen[id[i]] = version;
        }
    }

    cout << ans << '\n';
}