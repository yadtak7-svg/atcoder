#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> x(N);
    for (auto& y : x) cin >> y;
    vector<vector<pair<int, long long>>> T(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        --u, --v;
        T[u].push_back({v, w});
        T[v].push_back({u, w});
    }

    long long ans = 0;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
        for (auto [c, w] : T[v]) {
            if (c == p) continue;
            dfs(dfs, c, v);
            ans += w * abs(x[c]);
            x[v] += x[c];
        }
    };

    dfs(dfs, 0, -1);
    cout << ans << endl;
}
