#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n, k; cin >> n >> k;

    if(k >= 2 * (n - 1) && k % 2 == 0) cout << "Yes\n";
    else cout << "No\n";

}