#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int ans  = 0, t = -1;
    for(int i = 1; i <= n; i++) {
        ans += t * i * i * i;
        t *= -1;
    }

    cout << ans << '\n';
}