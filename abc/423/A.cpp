#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x, c; cin >> x >> c;
    int a = x / (c + 1000);

    cout << a * 1000 << '\n';
}