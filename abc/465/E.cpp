#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int dp[2][2][3][2][1 << 10];
int ndp[2][2][3][2][1 << 10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N;
    cin >> N;

    int L = N.size();

    dp[1][0][0][0][0] = 1;

    for (int pos = 0; pos < L; pos++) {

        memset(ndp, 0, sizeof(ndp));

        for (int tight = 0; tight <= 1; tight++) {

            int lim = tight ? N[pos] - '0' : 9;

            for (int started = 0; started <= 1; started++)
            for (int rem = 0; rem < 3; rem++)
            for (int has3 = 0; has3 <= 1; has3++)
            for (int mask = 0; mask < (1 << 10); mask++) {

                int cur = dp[tight][started][rem][has3][mask];
                if (!cur) continue;

                for (int d = 0; d <= lim; d++) {

                    int ntight = tight && (d == lim);

                    if (!started && d == 0) {

                        int &v = ndp[ntight][0][0][0][0];
                        v += cur;
                        if (v >= MOD) v -= MOD;

                    } else {

                        int nstarted = 1;
                        int nrem = (rem * 10 + d) % 3;
                        int nhas3 = has3 || (d == 3);
                        int nmask = mask | (1 << d);

                        int &v = ndp[ntight][nstarted][nrem][nhas3][nmask];
                        v += cur;
                        if (v >= MOD) v -= MOD;
                    }
                }
            }
        }

        memcpy(dp, ndp, sizeof(dp));
    }

    int ans = 0;

    for (int tight = 0; tight <= 1; tight++)
    for (int rem = 0; rem < 3; rem++)
    for (int has3 = 0; has3 <= 1; has3++)
    for (int mask = 0; mask < (1 << 10); mask++) {

        int cur = dp[tight][1][rem][has3][mask];
        if (!cur) continue;

        int A = (rem == 0);
        int B = has3;
        int C = (__builtin_popcount(mask) == 3);

        if (A + B + C == 1) {
            ans += cur;
            if (ans >= MOD) ans -= MOD;
        }
    }

    cout << ans << '\n';
}