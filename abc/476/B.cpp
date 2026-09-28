#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string S, T;
    cin >> S >> T;

    bool ok = true;
    for(int i = 0; i < n; i++)  {
        if(T[i] == '*') continue;
        if(S[i] != T[i]) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes\n" : "No\n");

}