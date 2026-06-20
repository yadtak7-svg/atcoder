#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long n;
    cin >> n;

    long long r = 2;
    long long ans = 0;

    while(r <= n) {
        long long s = sqrtl((long double)(n / r));
        ans += (s + 1) / 2;
        r *= 2;
    }

    cout << ans << endl;
}