#include <bits/stdc++.h>
using namespace std;

int dx[] = {-1,1,0,0}, dy[] = {0,0,-1,1};
char dir[] = {'>','<','v','^'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    vector<vector<char>> G(H,vector<char>(W));
    vector<vector<char>> ans(H, vector<char>(W, '#'));

    queue<pair<int,int>> q;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
            if(G[i][j] == 'E') {
                q.push({i, j});
                ans[i][j] = 'E';
            }
        }
    }

    while(!q.empty()) {
        auto[y, x] = q.front();
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if(!(0 <= ny && ny < H && 0 <= nx && nx < W)) continue;

            if(G[ny][nx] == '#') continue;  
            if(ans[ny][nx] != '#') continue; 

            ans[ny][nx] = dir[i];

            q.push({ny, nx});

        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << ans[i][j];
        }
        cout << "\n";
    }
}

    