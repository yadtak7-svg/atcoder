#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int H, W;
    cin >> H >> W;

    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            int ans= 0;
            if(i + 1 < H) ans++;
            if(i > 0) ans++;
            if(j + 1 < W) ans++;
            if(j > 0) ans++;
            cout << ans;
            if(j != W - 1) cout << " ";
        }
        cout << endl;
    }
}