#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> G;
vector<bool> visited;
vector<int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    G.resize(n);
    visited.resize(n, false);
    cnt.resize(n, 0);

    for(int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
        cnt[a]++, cnt[b]++;
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while(!q.empty()) {
        for(int v : G[q.front()]) {
            if(!visited[v]) {
                visited[v] = true;
                q.push(v);
            } 
        }
        q.pop();
    }

    bool ans = true;
    for(int i = 0; i < n; i++) {
        if(!visited[i] || cnt[i] != 2) {
            ans = false;
            break;
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}