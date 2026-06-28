#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, n;
    cin >> H >> W >> n;

    vector<vector<int>> diff(H+1, vector<int>(W+1, 0));

    while(n--) {
        int si, sj, gi, gj;
        cin >> si >> sj >> gi >> gj;
        si--; sj--; gi--; gj--;

        diff[si][sj] += 1;
        if(gi+1 < H) diff[gi+1][sj] -= 1;
        if(gj+1 < W) diff[si][gj+1] -= 1;
        if(gi+1 < H && gj+1 < W) diff[gi+1][gj+1] += 1;
    }

    vector<vector<int>> ans(H, vector<int>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            ans[i][j] = diff[i][j];
            if(i > 0) ans[i][j] += ans[i-1][j];
            if(j > 0) ans[i][j] += ans[i][j-1];
            if(i > 0 && j > 0) ans[i][j] -= ans[i-1][j-1];
        }
    }

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}
