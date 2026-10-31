#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int cnt = 0;
    for(char c : S) if(c == 'o') cnt++;

    cout << ((cnt % 2) ? "odd" : "even") << '\n';

}