#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> look(n, 0);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x; x--;
        look[x]++;
        ans = max(ans, look[x]);
    }

    cout << n - ans << "\n";
}