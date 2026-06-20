#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
queue<int> q;
vector<int> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    visited.resize(H * W + 1, 0);

    vector<vector<int>> G(H, vector<int>(W, INF));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            char c;
            cin >> c;
            if(c == '#') {
                G[i][j] = 0;
                q.push(i * H + j);
            }
        }
    }

    int dx[8] = {-1,-1,-1,0,0,1,1,1};
    int dy[8] = {-1,0,1,-1,1,-1,0,1};

    while(!q.empty()) {
        int x = q.front() % H;
        int y = q.front() / H;
        q.pop();

        for(int k = 0; k < 8; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

            if(G[nx][ny] == INF) {
                G[nx][ny] = G[x][y] + 1;
                q.push(ny * W);
            }
        }
    }

    vector<string> ans(H, string(W, '.'));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] % 2 == 0) {
                ans[i][j] = '#';
            }
        }
    }

    for(int i = 0; i < H; i++) {
        cout << ans[i] << '\n';
    }
}