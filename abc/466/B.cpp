#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> mx(m, -1);
    for(int i = 0; i < n; i++) {
        int c, s; cin >> c >> s;
        mx[c - 1] = max(mx[c - 1], s);
    }

    for(int x : mx) cout << x << ' ';
    cout << endl;
}