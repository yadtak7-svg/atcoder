#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;
    if(a + b == 9 || a - b == 9 || a * b == 9 || (a / b == 9 && a % b == 0)) cout << "Nine\n";
    else cout << "Nein\n";
}