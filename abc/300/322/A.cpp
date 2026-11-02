#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string S; cin >> S;
    for(int i = 0; i + 2 < n; i++) {
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C') {
            cout << i + 1 << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';
}