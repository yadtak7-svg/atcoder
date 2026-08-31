#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int H, W; cin >> H >> W;
        vector<int> G(H, vector<int>(W, 0));
        for(int i = 0; i < H; i++) {
            for(int j = 0; j < W; j++) {
                char c; cin >> c;
                if(c == '#') G[i][j] = 1;
            }
        }
    }
}