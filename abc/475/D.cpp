#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    const int MAX = 10000000;

    map<char, int> mp;
    vector<int> a(S.size());

    int cnt = 0;

    for (int i = 0; i < S.size(); i++) {
        if (!mp.count(S[i])) {
            mp[S[i]] = cnt++;
        }
        a[i] = mp[S[i]];
    }

    vector<bool> ok(MAX + 1, true);
    ok[0] = false;
    ok[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (!ok[i]) continue;

        for (int j = i * i; j <= MAX; j += i) {
            ok[j] = false;
        }
    }

    vector<int> p(10);
    iota(p.begin(), p.end(), 0);

    do {
        if (p[a[0]] == 0) continue;

        long long x = 0;

        for (int i = 0; i < S.size(); i++) {
            x = x * 10 + p[a[i]];
        }

        if (ok[x]) {
            cout << x << '\n';
            return 0;
        }

        if (cnt < 10 && p[cnt] == 9) {
        }

    } while (next_permutation(p.begin(), p.end()));

    cout << -1 << '\n';
}