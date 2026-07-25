#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    while(n--) {
        int x; cin >> x;
        m -= x;
    }

    if(m >= 0) cout << "Yes\n";
    else cout << "No\n";
} 