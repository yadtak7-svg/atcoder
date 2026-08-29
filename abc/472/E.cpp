#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> G(n);

        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            a--;
            b--;

            G[a].push_back(b);
            G[b].push_back(a);
        }

        vector<int> color(n, -1);
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);

        bool found = false;
        int start = -1, goal = -1;

        for(int s = 0; s < n; s++) {
            if(color[s] != -1) continue;

            queue<int> q;
            q.push(s);
            color[s] = 0;

            while(!q.empty() && !found) {
                int u = q.front();
                q.pop();

                for(int v : G[u]) {
                    if(color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        parent[v] = u;
                        depth[v] = depth[u] + 1;
                        q.push(v);
                    }
                    else if(color[v] == color[u]) {
                        // 奇数閉路を発見
                        found = true;
                        start = u;
                        goal = v;
                        break;
                    }
                }
            }

            if(found) break;
        }

        if(found) {
            vector<int> path1, path2;

            int a = start;
            int b = goal;

            while(depth[a] > depth[b]) {
                path1.push_back(a);
                a = parent[a];
            }

            while(depth[b] > depth[a]) {
                path2.push_back(b);
                b = parent[b];
            }

            while(a != b) {
                path1.push_back(a);
                path2.push_back(b);

                a = parent[a];
                b = parent[b];
            }

            path1.push_back(a);

            vector<int> cycle = path1;

            reverse(path2.begin(), path2.end());

            for(int x : path2) {
                cycle.push_back(x);
            }

            cout << cycle.size() << '\n';

            for(int v : cycle) {
                cout << v + 1 << ' ';
            }
            cout << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
}