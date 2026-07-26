#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, l, r; cin >> n >> l >> r;
    string S; cin >> S;
    bool ok = true;
    for(int i = l - 1; i < r; i++) if(S[i] == 'x') ok = false;

    cout << (ok ? "Yes\n" : "No\n");
}