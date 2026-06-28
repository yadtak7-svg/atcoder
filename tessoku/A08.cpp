#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W; cin >> H >> W;
    vector<vector<int>> G(H, vector<int>(W, 0));
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> G[i][j];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int ii = i - 1, jj = j - 1;

            if(0 <= ii) G[i][j] += G[ii][j];
            if(0 <= jj) G[i][j] += G[i][jj];
            if(0 <= ii && 0 <=jj) G[i][j] -= G[ii][jj];
        }
    }

    int q; cin >> q;
    while(q--) {
        int si, sj, gi, gj; cin >> si >> sj >> gi >> gj;
        si--; sj--; gi--; gj--;
        int ans = 0;
        ans += G[gi][gj];
        if(0 < si) ans -= G[si - 1][gj];  
        if(0 < sj) ans -= G[gi][sj - 1];
        if(0 < si && 0 < sj) ans += G[si - 1][sj - 1];
        cout << ans << '\n';
    }
}