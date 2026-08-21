#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W; cin >> H >> W;
    vector<string> G(H); 
    for(int i = 0; i < H; i++) cin >> G[i];

    bool ok = true;
    int di[] = {0, 0, 1, -1}, dj[] = {1, -1, 0, 0};
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(G[i][j] == '.') continue;

            int cnt = 0;
            for(int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if(0 > ni || H <= ni || 0 > nj || W <= nj) continue;

                if(G[ni][nj] == '#') cnt++;
            } 

            if(cnt != 2 && cnt != 4) ok = false;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");
}