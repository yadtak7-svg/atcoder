#include <bits/stdc++.h>
using namespace std;

long long solve(long long a, long long b, long long x, long long y) {
    assert((x + y) % 2 == 0);
    if (a > b) swap(a, b);
    if (x > y) swap(x, y);
    return min(2 * a * y, a * (x + y) + (b - a) * (y - x) / 2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;
        x = llabs(x);
        y = llabs(y);

        if ((x + y) % 2 == 1) {
            cout << min(solve(a, b, x - 1, y) + a,solve(a, b, x, y - 1) + b) << "\n";
        } else {
            cout << solve(a, b, x, y) << "\n";
        }
    }
    return 0;
}
