#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, H, W;
    cin >> H >> W >> n;

    vector<vector<int>> row(H), col(W);
    vector<bool> alive(n, 1);
    vector<int> X(n), Y(n), cnt_row(H, 0), cnt_col(W, 0);

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;

        X[i] = x, Y[i] = y;

        row[x].push_back(i);
        col[y].push_back(i);
        cnt_row[x]++;
        cnt_col[y]++;
    }

    int q; cin >> q;
    while(q--) {
        int t, x;
        cin >> t >> x;
        x--;

        if(t == 1) {
            cout << cnt_row[x] << endl;

            for (int id : row[x]) {
                if (!alive[id]) continue;

                alive[id] = false;

                int y = Y[id];
                cnt_row[x]--;
                cnt_col[y]--;
            }
            row[x].clear();
        }

        if(t == 2) {
            cout << cnt_col[x] << endl;

            for (int id : col[x]) {
                if (!alive[id]) continue;

                alive[id] = false;

                int r = X[id];
                cnt_row[r]--;
                cnt_col[x]--;
            }
            col[x].clear();
        }
    }
}