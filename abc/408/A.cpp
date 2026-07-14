#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s; cin >> n >> s;
    bool ok = true;
    vector<int> t(n + 1);
    t[0] = 0;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
        if(t[i] - t[i - 1] > s) ok = false;
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}