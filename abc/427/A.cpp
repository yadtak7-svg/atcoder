#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int len = S.size();
    for(int i = 0; i < len; i++) {
        if(i != len/2) cout << S[i];
    }
    cout << '\n';
}