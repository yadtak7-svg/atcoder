#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    int p = 0;  
    bool ok = true;

    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;

        int g = (x - 1) / 10; 
        if(g < p) ok = false;
        p = g;
    }

    cout << (ok ? "Yes\n" : "No\n");
}
