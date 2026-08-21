#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> A(6);
    map<long long, int> cnt;

    for (auto &x : A) {
        cin >> x;
        cnt[x]++;
    }

    long double ans = 0;

    for (auto [x, k] : cnt) {
        long double p = (long double)k / 6.0;

        long double e = 5.0L * x * (1.0L - pow(1.0L - p, 3));

        ans = max(ans, e);
    }

    cout << fixed << setprecision(15) << ans << '\n';
}