#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int,int>> A(n+1);
    vector<vector<int>> G(n+1);
    vector<bool> ok(n+1, false);

    for(int i = 1; i <= n; i++) {
        cin >> A[i].first >> A[i].second;
        auto [a, b] = A[i];

        if(a == 0 && b == 0) {
            ok[i] = true;
        } else {
            G[a].push_back(i);
            G[b].push_back(i);
        }
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) if(ok[i]) q.push(i);

    while(!q.empty()) {
        int x = q.front(); q.pop();
        for(int nxt : G[x]) {
            if(!ok[nxt]) {
                ok[nxt] = true;
                q.push(nxt);
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) if(ok[i]) cnt++;

    cout << cnt << '\n';
}
