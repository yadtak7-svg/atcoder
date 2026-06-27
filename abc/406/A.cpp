#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h1, h2, m1, m2;
    cin >> h1 >>  m1 >> h2 >> m2;

    bool ok = false;

    if(h1 > h2) ok = true;
    if(h1 == h2 && m1 > m2) ok = true;

    if(ok) cout << "Yes" << endl;
    else  cout << "No" << endl;
}