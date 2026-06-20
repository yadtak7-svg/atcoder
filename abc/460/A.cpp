#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    int ans = 0;
    while(m != 0) {
        m = n % m;
        ans++;
    }

    cout << ans << endl;
}