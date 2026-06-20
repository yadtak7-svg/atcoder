#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;

    vector<bool> used(26, false);
    for(char c : S) used[c - 'a'] = true;

    for(int i = 0; i < 26; i++) {
        if(!used[i]) {
            cout << (char)(i + 'a') << endl;
            return 0;
        }
    }
}