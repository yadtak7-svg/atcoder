#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    for(char c : S) {
        if(c != 'A') cout << '.';
        else cout << c;
    }
    cout << '\n';
}