#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string S; cin >> S;
        S = "0" + S;
        vector<bool> ok((1 << n), false);
        ok[0] = true;
        for(int i = 0; i < (1 << n) - 1; i++) {
            if(ok[i] == 0) continue;
            for(int j = 0; j < n; j++) {
                if(i & (1 << j)) continue;
                int nxt = (i | (1 << j));
                if(S[nxt] == '0') ok[nxt] = 1;
            }
        }

        cout << (ok[(1 << n) - 1] ? "Yes\n" : "No\n");    
    }
}