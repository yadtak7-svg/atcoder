#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<ll, ll>> A(n);
    vector<vector<pair<int, pair<ll, ll>>>> G(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        ll x, y;
        cin >> a >> b >> x >> y;
        a--; b--;

        G[a].push_back({b, {x, y}});
        G[b].push_back({a, {-x, -y}});
    }

    vector<bool> visited(n, false);
    vector<bool> bad(n, false);

    queue<int> q;
    q.push(0);
    visited[0] = true;

    while (!q.empty()) {
        int id = q.front();
        q.pop();

        for (auto [nx, d] : G[id]) {
            ll x = d.first;
            ll y = d.second;

            pair<ll, ll> next_pos = {
                A[id].first + x,
                A[id].second + y
            };

            if (!visited[nx]) {
                visited[nx] = true;
                A[nx] = next_pos;
                q.push(nx);
            }
            else if (A[nx] != next_pos) {
                bad[id] = true;
                bad[nx] = true;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (bad[i]) q.push(i);
    }

    while (!q.empty()) {
        int id = q.front();
        q.pop();

        for (auto [nx, d] : G[id]) {
            if (!bad[nx]) {
                bad[nx] = true;
                q.push(nx);
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i] || bad[i]) {
            cout << "undecidable\n";
        }
        else {
            cout << A[i].first << ' ' << A[i].second << '\n';
        }
    }
}