#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 
    vector<string> S(n);
    for(int i = 0; i < n; i++) cin >> S[i];

    int x; string s; cin >> x >> s; x--;

    cout << (S[x] == s ? "Yes" : "No") << '\n';
}