#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<bool> used(m, false);

    int last = 0;

    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a > m) continue;
        a--;
        if(!used[a]) {
            used[a] = true;
            last = max(i, last);
        }
    }

    for(int i = 0; i < m; i++) {
        if(!used[i]) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << n - last << endl;
}