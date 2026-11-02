#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    for(int i = 1; i < S.size(); i += 2) {
        if(S[i] != '0') {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}