#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int W, H; cin >> H >> W;
    
    if(W * 10000  >= 25 * H * H) cout << "Yes\n";
    else cout << "No\n";
}