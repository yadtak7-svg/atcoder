#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> H(N);
    vector<ll> L(N);

    for (int i = 0; i < N; i++) {
        cin >> H[i] >> L[i];
    }

    vector<int> suf(N);
    suf[N - 1] = H[N - 1];

    for (int i = N - 2; i >= 0; i--) {
        suf[i] = max(suf[i + 1], H[i]);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        ll T;
        cin >> T;

        int idx = upper_bound(L.begin(), L.end(), T) - L.begin();
        cout << suf[idx] << "\n";
    }

    return 0;
}