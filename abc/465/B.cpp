#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y, l, r, a, b;
    cin >> x >> y >> l >> r >> a >> b;

    int ans = 0;
    for(int t = a; t < b; t++){
        if(l <= t && t < r) ans += x;
        else ans += y;
    }

    cout << ans << endl;
}
