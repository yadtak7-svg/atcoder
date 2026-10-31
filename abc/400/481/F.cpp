#include <bits/stdc++.h>
using namespace std;

int main() {
    const long long MOD = 998244353;
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> g(n + 1);
    vector<vector<pair<int,int>>> rg(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        g[u].push_back(v);
        rg[v].push_back({u, c});
    }

    vector<int> dist(n + 1, -1), order;
    dist[1] = 0;
    order.push_back(1);
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                order.push_back(v);
                q.push(v);
            }
        }
    }

    vector<int> rnk(n + 1, 0);
    vector<long long> score(n + 1, 0);
    vector<pair<int,int>> key(n + 1);  
    vector<int> par(n + 1, 0), pc(n + 1, 0);

    size_t i = 1;  
    while (i < order.size()) {
        int d = dist[order[i]];
        size_t j = i;
        while (j < order.size() && dist[order[j]] == d) j++;

        for (size_t k = i; k < j; k++) {
            int v = order[k];
            pair<int,int> best = {INT_MAX, INT_MAX};
            for (auto [u, c] : rg[v]) {
                if (dist[u] == d - 1) {
                    pair<int,int> cand = {rnk[u], c};
                    if (cand < best) {
                        best = cand;
                        par[v] = u;
                        pc[v] = c;
                    }
                }
            }
            key[v] = best;
        }

        sort(order.begin() + i, order.begin() + j,
             [&](int a, int b) { return key[a] < key[b]; });
        int r = 0;
        for (size_t k = i; k < j; k++) {
            int v = order[k];
            if (k > i && key[v] != key[order[k - 1]]) r++;
            rnk[v] = r;
            score[v] = (score[par[v]] * 10 + pc[v]) % MOD;
        }
        i = j;
    }

    for (int v = 2; v <= n; v++) {
        if (dist[v] < 0) printf("-1\n");
        else printf("%lld\n", score[v]);
    }
    return 0;
}