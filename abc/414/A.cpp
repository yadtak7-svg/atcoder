#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, r; cin >> n >> l >> r;
    int ans = 0;
    while(n--) {
        int a, b; cin >> a >> b;
        if(a <= l && r <= b) ans++;
    }

    cout << ans << '\n';
}