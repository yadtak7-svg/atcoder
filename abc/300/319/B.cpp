#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for(int i = 0; i <= n; i++) {
        bool ok = false;

        for(int j = 1; j <= 9; j++) {
            if(n % j == 0 &&  i % (n/j) == 0) {
                cout << j;
                ok = true;
                break;
            }
        }
        if(!ok) cout << '-';
    }

    cout << '\n';

}