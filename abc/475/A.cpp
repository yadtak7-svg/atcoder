#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int n = S.size();
    n = n * 2 - 1;
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            cout << S[i / 2];
        }
        else cout << 'o';
    }
}