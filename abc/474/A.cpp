#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x; cin >> x;

    if(x != 1) {
        cout << 1 << '\n';
        return 0;
    }
    else if(x != 2) {
        cout << 2 << '\n';
        return 0;
    }

    else cout << 3 << '\n';
}