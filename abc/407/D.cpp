#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    unsigned H, W; cin >> H >> W;
    vector<vector<unsigned long>> A(H, vector<unsigned long>(W));

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            cin >> A[i][j];
        }
    }

    vector<unsigned> can{0};
    const unsigned Y = (1U << W) + 1, X = 3;    

    for(unsigned i = 0, bit = 0; i < H; ++i) {
        for(int j = 0; j < W; ++j, ++bit) {
            vector<unsigned> tmp;
            for(const auto b : can) {
                if(j + 1 < W && !(b & X << bit)) tmp.emplace_back(b | X << bit);
                if(i + 1 < H && !(b & Y << bit)) tmp.emplace_back(b | Y << bit);
            }
            move(tmp.begin(), tmp.end(),back_inserter(can));
        }
    }

    unsigned long ans = 0;
    for(const auto b : can) {
        unsigned long cur = 0;
        for(unsigned i = 0, bit = 0; i < H; ++i) {
            for(unsigned j = 0; j < W; ++j, ++bit) {
                if(1 & ~b >> bit) cur ^= A[i][j];
            }
        }
        ans = max(ans, cur);
    }

    cout << ans << endl;
}