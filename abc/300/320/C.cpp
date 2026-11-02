#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<string> S(3);
    for (int i = 0; i < 3; i++) cin >> S[i];

    int ans = 1e9;

    vector<int> p = {0, 1, 2};

    for (int d = 0; d <= 9; d++) {
        do {
            int cur = 0;
            bool ok = true;

            for (int k = 0; k < 3; k++) {
                while (S[p[k]][cur % n] - '0' != d) {
                    cur++;

                    if (cur == 3 * n) {
                        ok = false;
                        break;
                    }
                }

                if (!ok) break;

                cur++;
            }

            if (ok) ans = min(ans, cur - 1);

        } while (next_permutation(p.begin(), p.end()));
    }

    if (ans == 1e9) ans = -1;

    cout << ans << '\n';
}