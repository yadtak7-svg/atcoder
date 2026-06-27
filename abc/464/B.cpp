#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int min_r = H, max_r = -1;
    int min_c = W, max_c = -1;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(S[i][j] == '#') {
                min_r = min(min_r, i);
                max_r = max(max_r, i);
                min_c = min(min_c, j);
                max_c = max(max_c, j);
            }
        }
    }

    for(int i = min_r; i <= max_r; i++) {
        for(int j = min_c; j <= max_c; j++) {
            cout << S[i][j];
        }
        cout << '\n';
    }

}