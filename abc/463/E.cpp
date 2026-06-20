#include <bits/stdc++.h>
using namespace std;

const long long INF = 1LL << 60;

int n, m, y;
vector<vector<pair<int,long long>>> G;
vector<long long> X;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m >> y;
    G.resize(n + 2);
    X.resize(n + 1);

    int S = n + 1;

    for(int i = 0; i < m; i++) {
        int u, v; long long t;
        cin >> u >> v >> t;
        G[u].push_back({v, t});
        G[v].push_back({u, t}); 
    }
    for(int i = 1; i <= n; i++) cin >> X[i];
    

    for(int i = 1; i <= n; i++){
        G[i].push_back({S,X[i]});
        G[S].push_back({i,X[i]+ y});
    }

    vector<long long> dist(n + 2, INF);
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();

        if (d != dist[v]) continue;

        for (auto [to, w] : G[v]) {
            if (dist[to] > d + w) {
                dist[to] = d + w;
                pq.push({dist[to], to});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}


