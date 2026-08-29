#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W, k; cin >> H >> W >> k;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];
    vector<bool> row(H, false), col(W, false);
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') row[i] = true, col[j] = true;
        }
    }

    vector<pair<int, int>> safe;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.' && !row[i] && !col[j]) safe.push_back({i, j});
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> dist(H, vector<int>(W, -1));

    for(auto [i, j] : safe) {
        dist[i][j] = 0;
        q.push({i, j});
    }

    int di[] = {-1, 1, 0, 0};
    int dj[] = {0, 0, -1, 1};

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for(int d = 0; d < 4; d++) {
            int ni = i + di[d];
            int nj = j + dj[d];

            if(ni < 0 || ni >= H || nj < 0 || nj >= W)
                continue;

            if(S[ni][nj] == '#')
                continue;

            if(dist[ni][nj] != -1)
                continue;

            if(dist[i][j] == k)
                continue;

            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});
        }
    }

    long long ans = 0;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '.' && dist[i][j] != -1) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}