
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int m = 2 * n - 1;
    vector<vector<int>> G(m);

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;

        int w = n + i;

        G[u].push_back(w);
        G[v].push_back(w);
        G[w].push_back(u);
        G[w].push_back(v);
    }

    vector<int> C(m, 0);

    for(int i = 0; i < n; i++) {
        cin >> C[i];
        --C[i];
    }

    auto bfs_dist = [&](int root) -> vector<int> {
        vector<int> dist(m, m);
        queue<int> q;

        dist[root] = 0;
        q.push(root);

        while(!q.empty()) {
            int x = q.front();
            q.pop();

            for(int y : G[x]) {
                if(dist[y] != m) continue;

                dist[y] = dist[x] + 1;
                q.push(y);
            }
        }

        return dist;
    };

    auto find = [&](const vector<int>& dist) {
        return max_element(dist.begin(), dist.end())
               - dist.begin();
    };

    auto dist0 = bfs_dist(0);
    int v1 = find(dist0);

    auto dist1 = bfs_dist(v1);
    int v2 = find(dist1);

    auto dist2 = bfs_dist(v2);

    int diam = dist1[v2];
    int center = -1;

    assert(diam % 2 == 0);

    for(int i = 0; i < m; i++) {
        if(dist1[i] == diam / 2 &&
           dist2[i] == diam / 2) {
            center = i;
            break;
        }
    }

    
    auto dist = bfs_dist(center);

    
    long long ans = 0;

    vector<int> count_total(n, 0);
    vector<int> count_subtree(n, 0);

    int radius = diam / 2;

    for(int root : G[center]) {

        stack<pair<int, int>> st;
        st.push({root, center});

        vector<int> look;

        while(!st.empty()) {
            auto [x, p] = st.top();
            st.pop();

            if(dist[x] == radius) {
                int c = C[x];

                ans += count_total[c] - count_subtree[c];

                if(count_subtree[c] == 0) {
                    look.push_back(c);
                }

                count_total[c]++;
                count_subtree[c]++;
            }

            for(int y : G[x]) {
                if(y == p) continue;
                st.push({y, x});
            }
        }
        
        for(int c : look) {
            count_subtree[c] = 0;
        }
    }

    cout << ans << '\n';

    return 0;
}
