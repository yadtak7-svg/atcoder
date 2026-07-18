#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int ans = 0;
    while(n--) {
        int a, b; cin >> a >> b;
        string s; cin >> s;
        if(s == "keep") ans += b - a;
    }

    cout << ans << endl;
}