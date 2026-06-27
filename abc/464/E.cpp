#include <bits/stdc++.h>
using namespace std;

struct Query {
    int r, c;
    char x;
};

struct BIT {
    int n;
    vector<int> bit;

    BIT(int n) : n(n), bit(n + 1, -1) {}

    void update(int i, int x) {
        while (i <= n) {
            bit[i] = max(bit[i], x);
            i += i & -i;
        }
    }

    int query(int i) {
        int res = -1;
        while (i > 0) {
            res = max(res, bit[i]);
            i -= i & -i;
        }
        return res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, Q;
    cin >> H >> W >> Q;

    vector<Query> qs(Q);
    for (int i = 0; i < Q; i++) {
        cin >> qs[i].r >> qs[i].c >> qs[i].x;
        qs[i].r--;
        qs[i].c--;
    }

    vector<vector<int>> row(H);
    for (int i = 0; i < Q; i++) {
        row[qs[i].r].push_back(i);
    }

    vector<string> ans(H, string(W, 'A'));

    BIT fw(W);

    for (int r = H - 1; r >= 0; r--) {
        for (int id : row[r]) {
            int pos = W - qs[id].c;
            fw.update(pos, id);
        }

        for (int c = 0; c < W; c++) {
            int pos = W - c;
            int id = fw.query(pos);

            if (id != -1) {
                ans[r][c] = qs[id].x;
            }
        }
    }

    for (auto &s : ans) {
        cout << s << '\n';
    }

    return 0;
}