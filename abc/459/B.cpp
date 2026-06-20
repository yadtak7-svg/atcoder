#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string res;
    for(int i = 0; i < n; i++) {
        string S;
        cin >> S;

        int c = S[0] - 'a';

        int ans;
        if(c < 3) ans = 2;
        else if(c < 6) ans = 3;
        else if(c < 9) ans = 4;
        else if(c < 12) ans = 5;
        else if(c < 15) ans = 6;
        else if(c < 19) ans = 7;
        else if(c < 22) ans = 8;
        else ans = 9;

        res.push_back(ans + '0');
    }

    cout << res << endl;
}