#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int x = 1;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        char c; cin >> c;
        if(c == 'x') x++;
        else x = 0;

        if(x >= 3) ans++;
    }
    x++;
    if(x >= 3) ans++;

    cout << ans << "\n";
}