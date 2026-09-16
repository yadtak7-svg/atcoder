#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;

    long long o = 0, t = 0, h = 0;

    while (n--) {
        long long A;
        cin >> A;

        long long k = (A + 999) / 1000;   
        long long x = 1000 * k - A;

        h += x / 100;
        x %= 100;

        t += x / 10;
        x %= 10;

        o += x;
    }

    cout << o << " " << t << " " << h << "\n";
}
