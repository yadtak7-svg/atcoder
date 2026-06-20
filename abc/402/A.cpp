#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    for(char c : S) {
        if('A' <= c && c <= 'Z') cout << c;
    }

    cout << endl;
}