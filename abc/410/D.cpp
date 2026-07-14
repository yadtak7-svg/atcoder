#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> G;
vector<vector<bool>> vis;

void dfs(int v, int x){
    if(vis[v][x]) return;
    vis[v][x] = true;

    for(auto [to,w] : G[v]){
        dfs(to, x ^ w);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    G.resize(n);
    vis.assign(n, vector<bool>(1024, false));

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;

        G[u].push_back({v, w});
    }

    dfs(0, 0);

    for(int x = 0; x < 1024; x++){
        if(vis[n - 1][x]){
            cout << x << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}