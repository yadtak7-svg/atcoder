#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    string ans;
    for(char c : S) if('0' <= c && c <= '9') ans.push_back(c);

    cout << ans << endl;
}