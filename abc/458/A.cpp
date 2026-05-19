#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    int n;
    cin >> n;

    for(int i = 0; i < S.size(); i++) {
        if(n <= i && i < S.size() - n) cout << S[i];
    }
    cout << endl;

}