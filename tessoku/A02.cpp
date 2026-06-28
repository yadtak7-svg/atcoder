#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x; cin >> n >> x;
    bool ok = false;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        if(a == x) ok = true;
    }

    if(ok) cout << "Yes" << endl;
    else   cout << "No"  << endl;
}