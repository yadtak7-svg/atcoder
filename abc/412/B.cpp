#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S, T; cin >> S >> T;
    vector<bool> A(26, false), a(26, false);
    for(char c : T) {
        if('a' <= c  && c <= 'z') a[c - 'a'] = true;
        else if('A' <= c && c <= 'Z') A[c - 'A'] = true;
    }

    bool ok = true;
    for(int i = 1; i < S.size(); i++) {
        if('A' <= S[i] && S[i] <= 'Z') {
            if('a' <= S[i - 1] && S[i - 1] <= 'z' && !a[S[i - 1] - 'a']) ok = false;
            if('A' <= S[i - 1] && S[i - 1] <= 'Z' && !A[S[i - 1] - 'A']) ok = false;
        } 
    }

    cout << (ok ? "Yes" : "No") << '\n';
}