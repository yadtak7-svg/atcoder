#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string T, U;
    cin >> T; 
    cin >> U;

    int t = T.size();
    int u = U.size();

    for(int i = 0; i <= t - u; i++) {
        bool ok = true;
        for(int j = 0; j < u; j++) {
            ok = (T[i + j] == U[j] || T[i + j] == '?');
            if(!ok) break;
        }
        if(ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
}