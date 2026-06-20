#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    char c;
    cin >> n >> c;
    int t = c - 'A';
    bool ok = false;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 5; j++) {
            char a; cin >> a;
            if(j == t && a == 'o') ok = true;
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}