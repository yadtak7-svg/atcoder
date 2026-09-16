#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;

    vector<vector<int>> G(H, vector<int>(W, 0));
    int di[] = {0, 0, -1, 1};
    int dj[] = {-1, 1, 0, 0};
    int ans = 0;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            char c; cin >> c;
            if (c == '#') { G[i][j] = -1; ans++; }
        }

    queue<pair<int,int>> que;

    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            if (G[i][j] == -1) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                int ni = i+di[k], nj = j+dj[k];
                if (ni<0||ni>=H||nj<0||nj>=W) continue;
                if (G[ni][nj] == -1) cnt++;
            }
            G[i][j] = min(cnt, 2);
            if (G[i][j] == 1) que.push({i,j});
        }

    while (!que.empty()) {
        int sz = que.size();
        vector<pair<int,int>> T;

        for (int t = 0; t < sz; t++) {
            auto [i,j] = que.front(); que.pop();
            if (G[i][j] == 1) T.push_back({i,j});
        }

        for (auto &[i,j] : T) G[i][j] = -1;

        for (auto &[i,j] : T) {
            for (int k = 0; k < 4; k++) {
                int ni = i+di[k], nj = j+dj[k];
                if (ni<0||ni>=H||nj<0||nj>=W) continue;
                if (G[ni][nj] >= 0) {
                    G[ni][nj] = min(G[ni][nj] + 1, 2);
                    if (G[ni][nj] == 1) que.push({ni, nj});
                }
            }
        }

        ans += T.size();
    }

    cout << ans << '\n';
}