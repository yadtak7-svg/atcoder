#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, int g, vector<vector<int>>& G, vector<int>& path, vector<bool>& visited) {
    visited[u] = true;
    path.push_back(u);

    if (u == g) return true;

    for (int v : G[u]) {
        if (!visited[v]) {
            if (dfs(v, g, G, path, visited)) return true;
        }
    }

    path.pop_back();
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; 
    cin >> t;
    while (t--) {
        int n, m, s, g;
        cin >> n >> m >> s >> g;
        s--; g--;

        vector<vector<int>> G(n);
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            G[a].push_back(b);
            G[b].push_back(a);
        }

        for (int i = 0; i < n; i++) {
            sort(G[i].begin(), G[i].end());
        }

        vector<bool> visited(n, false);
        vector<int> path;

        bool ok = dfs(s, g, G, path, visited);

        if (!ok) {
            cout << -1 << "\n";
        } else {
            for (int x : path) cout << x + 1 << " ";
            cout << "\n";
        }
    }
}
