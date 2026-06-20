#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S[3] = {"login", "logout", "private"};

    int n;
    cin >> n;

    int ans = 0;
    bool status = 0;
    while(n--) {
        string com;
        cin >> com;

        if(com == S[0]) status = 1;
        else if(com == S[1]) status = 0;
        else if(com == S[2] && status == 0) ans++; 
    }

    cout << ans << endl;


}