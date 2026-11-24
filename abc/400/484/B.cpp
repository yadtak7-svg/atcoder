#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k; cin >> k;
    int ans = 100;
    bool ex9 = false;
    while(k--) {
        int a; cin >> a;
        if(a == 9) {
            ex9 = true;
        }
        
        ans = min(ans, a);
        
    }

    if(!ex9) {
        ans = -1;
    }

    cout << ans << '\n';

}