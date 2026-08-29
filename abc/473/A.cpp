#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int h =  n / 2;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(i >= h) ans += x; 
    }

    cout << ans << '\n';
}