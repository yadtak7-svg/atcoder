#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using mint = modint998244353;
using i128 = __int128_t;

long long gcd_ll(long long a, long long b) {
    while (b) {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        long long N, M;
        cin >> N >> M;

        string s = to_string(N);
        int L = (int)s.size();

        vector<long long> cntY(L + 1);

        long long p10 = 1;
        for (int d = 1; d < L; d++) {
            cntY[d] = 9 * p10;
            p10 *= 10;
        }

        long long lower = 1;
        for (int i = 1; i < L; i++) lower *= 10;
        cntY[L] = N - lower + 1;

        mint ans = 0;

        i128 pow10 = 1;
        for (int d = 1; d <= L; d++) {
            pow10 *= 10;

            i128 rep = pow10 - 1;

            long long g = std::gcd<long long>(
                M,
                (long long)(rep % M)
            );

            long long t = M / g;

            long long cntX = N / t;

            ans += mint(cntX) * mint(cntY[d]);
        }

        cout << ans.val() << '\n';
    }

    return 0;
}