#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

void update(int u, int v, long long wUV, long long wVU, vector<vector<long long>>& D, int V) {
    if (wUV < D[u][v]) D[u][v] = wUV;
    if (wVU < D[v][u]) D[v][u] = wVU;

    for (int i = 0; i < V; i++) {
        long long diu = D[i][u];
        long long div = D[i][v];
        if (diu == INF && div == INF) continue;
        for (int j = 0; j < V; j++) {
            long long via1 = (diu == INF || D[v][j] == INF) ? INF : diu + D[u][v] + D[v][j];
            long long via2 = (div == INF || D[u][j] == INF) ? INF : div + D[v][u] + D[u][j];
            long long best = min({D[i][j], via1, via2});
            if (best < D[i][j]) D[i][j] = best;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<pair<int, long long>>> G(n + 1);
    int k, T;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({b, c});
        G[b].push_back({a, c});
    }

    cin >> k >> T;
    for (int i = 0; i < k; i++) {
        int d; cin >> d;
        G[0].push_back({d, T});   
        G[d].push_back({0, 0});   
    }

    int V = n + 1;
    vector<vector<long long>> D(V, vector<long long>(V, INF));
    for (int i = 0; i < V; i++) D[i][i] = 0;

    for (int u = 0; u < V; u++)
        for (auto& [v, w] : G[u])
            D[u][v] = min(D[u][v], w);

    for (int mid = 0; mid < V; mid++)
        for (int i = 0; i < V; i++) {
            if (D[i][mid] == INF) continue;
            for (int j = 0; j < V; j++) {
                if (D[mid][j] == INF) continue;
                if (D[i][mid] + D[mid][j] < D[i][j])
                    D[i][j] = D[i][mid] + D[mid][j];
            }
        }

    int q; cin >> q;
    while (q--) {
        int type; cin >> type;

        if (type == 1) {
            int x, y; long long w;
            cin >> x >> y >> w;
            update(x, y, w, w, D, V);
        }
        if (type == 2) {
            int x; cin >> x;
            update(0, x, T, 0, D, V); 
        }
        if (type == 3) {
            long long ans = 0;
            for (int i = 1; i <= n; i++) {          
                for (int j = i + 1; j <= n; j++) {
                    if (D[i][j] != INF) ans += D[i][j];
                }
            }
            ans *= 2;
            cout << ans << "\n";
        }
    }

    return 0;
}