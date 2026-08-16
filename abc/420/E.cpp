#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par;
    vector<int> sz;
    vector<int> black;

    DSU(int n) : par(n), sz(n, 1), black(n, 0) {
        iota(par.begin(), par.end(), 0);
    }

    int root(int x) {
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);

        if (x == y) return;

        if (sz[x] < sz[y]) swap(x, y);

        par[y] = x;
        sz[x] += sz[y];

        black[x] += black[y];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    DSU dsu(N);

    vector<bool> color(N, false);

    while (Q--) {
        int t; cin >> t;

        if (t == 1) {
            int u, v;
            cin >> u >> v;
            --u;
            --v;

            dsu.unite(u, v);
        }
        else if (t == 2) {
            int v;
            cin >> v;
            --v;

            int r = dsu.root(v);

            if (color[v]) {
                color[v] = false;
                dsu.black[r]--;
            }
            else {
                color[v] = true;
                dsu.black[r]++;
            }
        }
        else {
            int v;
            cin >> v;
            --v;

            int r = dsu.root(v);

            if (dsu.black[r] > 0) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
    }
}