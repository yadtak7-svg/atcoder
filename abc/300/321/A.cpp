#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S; cin >> S;
    int s = S.size();

    int cur = S[0] - '0';
    for(int i = 1; i < s; i++) {
        if(S[i] - '0' < cur) cur = S[i] - '0';
        else {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

 }