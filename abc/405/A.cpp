#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int r, x;
    cin >> r >> x;

    bool ok = false;
    if(x == 1 && 1600 <= r && r <= 2999) ok = true;
    if(x == 2 && 1200 <= r && r <= 2399) ok = true;
    
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}