#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    const int lim = 300010;
    vector<bool> check(lim, true);

    for(int i = 2; i < lim; i++) {
        if(!check[i]) continue;
        for(int j = i + i; j < lim; j += i) {
            check[j] = false;
        }
    }

    int q; cin >> q;
    while(q--) {
        int x; cin >> x;
        if(check[x]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}