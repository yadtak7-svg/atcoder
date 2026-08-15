#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string T;
    cin >> T;

    long long cnt[2] = {1, 0};

    int parity = 0;
    long long ans = 0;

    for (char c : T) {
        if (c == '0') {
            parity ^= 1;
        }

        ans += cnt[parity];

        cnt[parity]++;
    }

    cout << ans << '\n';
}