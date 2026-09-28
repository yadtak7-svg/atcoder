#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    string r = "r", er = "er";

    if(S[S.size() - 1] == 'e') S += r;
    else S += er;

    cout << S << '\n';
}