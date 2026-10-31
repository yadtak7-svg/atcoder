#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(
    const vector<vector<pair<int, int>>> &G,
    int n,
    int s
) {
    const int INF = 1e9;
    vector<int> dist(n, INF);

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (auto [to, cost] : G[v]) {
            if (dist[to] > d + cost) {
                dist[to] = d + cost;
                pq.push({dist[to], to});
            }
        }
    }

    return dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;
    --s;
    --t;

    vector<vector<pair<int, int>>> G(n);
    vector<int> a(n, n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        G[u].push_back({v, 1});

        a[u] = min(a[u], v);
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != n) {
            G[i].push_back({a[i], 0});
        }
    }

    vector<int> dist = dijkstra(G, n, s);

    if (dist[t] == 1e9) {
        cout << -1 << '\n';
    } else {
        cout << dist[t] << '\n';
    }

    return 0;
}