#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, s; cin >> n >> s;
    vector<bool> ok(s + 1, false);
    ok[0] = true;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        for(int j = s - a; j >= 0; j--) {
            if(ok[j]) ok[a + j] = true;
        }
    }

    if(ok[s]) cout << "Yes\n";
    else cout << "No\n";
}