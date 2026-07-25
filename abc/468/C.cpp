#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> perms;
vector<int> cur;
vector<bool> used;

void gen(int n) {
    if ((int)cur.size() == n) {
        perms.push_back(cur);
        return;
    }
    for (int x = 1; x <= n; x++) {
        if (!used[x]) {
            used[x] = true;
            cur.push_back(x);
            gen(n);
            cur.pop_back();
            used[x] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> P(n), Q(n);
    for (int i = 0; i < n; i++) cin >> P[i];
    for (int i = 0; i < n; i++) cin >> Q[i];

    used.assign(n+1, false);
    gen(n);

    int ans = 0;
    for (auto& v : perms) {
        if (P < v && v < Q) ans++;
    }

    cout << ans << '\n';
}
