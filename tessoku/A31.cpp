#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n; cin >> n;
    long long ans = (n / 3) + (n / 5) - (n / 15);
    cout << ans << endl;
}