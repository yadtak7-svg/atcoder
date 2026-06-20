#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, K;
vector<pair<ll,ll>> P; 
vector<ll> R;

bool ok(ll x) {
    vector<int> dp(N + 1);

    for (int i = 1; i <= N; i++) {
        ll lim = P[i - 1].second - max(1LL, x);

        int pre = upper_bound(
            R.begin(),
            R.begin() + (i - 1),
            lim
        ) - R.begin();

        dp[i] = max(dp[i - 1], dp[pre] + 1);
    }

    return dp[N] >= K;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> K;

    P.resize(N);
    R.resize(N);

    ll LMIN = (1LL << 60);
    ll RMAX = -(1LL << 60);

    for (int i = 0; i < N; i++) {
        ll L, RR;
        cin >> L >> RR;

        P[i] = {RR, L};

        LMIN = min(LMIN, L);
        RMAX = max(RMAX, RR);
    }

    sort(P.begin(), P.end());

    for (int i = 0; i < N; i++) {
        R[i] = P[i].first;
    }

    if (!ok(0)) {
        cout << -1 << "\n";
        return 0;
    }

    ll okv = 0;
    ll ng = RMAX - LMIN + 1;

    while (ng - okv > 1) {
        ll mid = (okv + ng) / 2;

        if (ok(mid))
            okv = mid;
        else
            ng = mid;
    }

    cout << okv << "\n";

    return 0;
}