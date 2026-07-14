/*

#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, long long>>> G;

bool rm(long long ban) {
    queue<int> que;
    vector<bool> vis(n, false);
    que.push(0);
    vis[0] = true;

    while(!que.empty()) {
        int top = que.front();
        que.pop();
        
        if(top == n - 1) return true;

        for(auto [to, w] : G[top]) {
            if(vis[to]) continue;
            if(w & ban) continue;

            vis[to] = true;
            que.push(to);
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    G.resize(n);

    for(int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w; u--, v--;
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    long long ban = 0;
    long long ans = 0;

    for(int i = 30; i >= 0; i--) {
        ban |= (1LL << i);
        
        if(!rm(ban)) {
            ban ^= (1LL << i);
            ans |= (1LL << i);
        }
    }

    cout << ans << endl;
}

*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int w;
};

int n, m;
vector<vector<Edge>> G;

vector<int> vis;
int timer_id = 0;

bool reachable(int ban) {
    ++timer_id;

    queue<int> q;
    q.push(0);
    vis[0] = timer_id;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == n - 1) return true;

        const auto& adj = G[v];

        for (int i = 0; i < (int)adj.size(); i++) {
            int to = adj[i].to;
            int w  = adj[i].w;

            if (w & ban) continue;
            if (vis[to] == timer_id) continue;

            vis[to] = timer_id;
            q.push(to);
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    G.resize(n);
    vis.assign(n, 0);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u;
        --v;

        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }

    int ban = 0;
    int ans = 0;

    for (int b = 29; b >= 0; b--) {
        ban |= (1 << b);

        if (!reachable(ban)) {
            ban ^= (1 << b);
            ans |= (1 << b);
        }
    }

    cout << ans << '\n';
}