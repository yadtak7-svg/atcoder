#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N;
    cin >> N;

    long long start, goal;
    cin >> start;

    vector<long long> A;
    for (int i = 1; i < N - 1; i++) {
        long long x;
        cin >> x;
        A.push_back(x);
    }

    cin >> goal;

    sort(A.begin(), A.end());

    int ans = 2; 

    while (start * 2 < goal) {
        auto it = upper_bound(A.begin(), A.end(), start * 2);

        if (it == A.begin()) {
            cout << -1 << '\n';
            return;
        }

        --it;

        if (*it <= start) {
            cout << -1 << '\n';
            return;
        }

        start = *it;
        ans++;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) solve();
}