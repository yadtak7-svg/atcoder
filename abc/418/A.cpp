#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string S; cin >> S;

    bool ok = false;
    if(S[n - 3] == 't' && S[n - 2] == 'e' && S[n - 1] == 'a') ok = true;

    if(ok) cout << "Yes\n";
    else cout << "No\n";
}