#include <bits/stdc++.h>
using namespace std;

int H, W;
int gi, gj;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};

vector<vector<char>> grid;
vector<vector<vector<int>>> dist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> H >> W;

    grid.resize(H, vector<char>(W));

    int si, sj;

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> grid[i][j];

            if (grid[i][j] == 'S') {
                si = i;
                sj = j;
            }
            else if (grid[i][j] == 'G') {
                gi = i;
                gj = j;
            }
        }
    }

    dist.assign(H, vector<vector<int>>(W, vector<int>(2, -1)));

    queue<tuple<int, int, int>> q;

    dist[si][sj][0] = 0;
    q.push({si, sj, 0});

    while (!q.empty()) {
        auto [i, j, sts] = q.front();
        q.pop();

        if (i == gi && j == gj) {
            cout << dist[i][j][sts] << '\n';
            return 0;
        }

        for (int k = 0; k < 4; k++) {
            int ni = i + di[k];
            int nj = j + dj[k];

            if (ni < 0 || ni >= H || nj < 0 || nj >= W) {
                continue;
            }

            char c = grid[ni][nj];

            if (c == '#' || c == 'x' || c == 'o') {
                if (c == '#') continue;
                if (c == 'x' && sts == 0) continue;
                if (c == 'o' && sts == 1) continue;
            }

            int nsts = sts;

            if (c == '?') {
                nsts ^= 1;
            }

            if (dist[ni][nj][nsts] != -1) {
                continue;
            }

            dist[ni][nj][nsts] = dist[i][j][sts] + 1;
            q.push({ni, nj, nsts});
        }
    }

    cout << -1 << '\n';
}