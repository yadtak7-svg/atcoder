#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int m; cin >> m; m--;
    int d; cin >> d;
    m = (m + d) % 12;
    cout << m + 1 << '\n';
    
}