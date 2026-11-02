#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long a, b; cin >> a >> b;
    cout << (long long)(pow(a, b) + pow(b, a)) << '\n';

}