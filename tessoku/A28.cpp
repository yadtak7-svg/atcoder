#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x = 0; 
    int n; cin >> n;
    while(n--) {
        char op; int a; cin >> op >> a;
        if(op == '+') x += a;
        else if(op == '-') x -= a;
        else if(op == '*') x *= a;
        if(x < 0) x += 10000;
        x %= 10000;
        cout << x << '\n';
    }
}