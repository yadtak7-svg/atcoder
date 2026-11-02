#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    string S, T; cin >> S >> T;

    string h = T.substr(0, n);
    string t = T.substr(m - n);

    if(h == S && t == S) {
        cout << 0 << '\n';
    }
    else if(h == S) {
        cout << 1 << '\n';
    }
    else if(t == S) {
        cout << 2 << '\n';
    }
    else {
        cout << 3 << '\n';
    }


}