#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> exist(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        exist[a][b] = exist[b][a] = 1;
    }

    vector<int> P(n);
    iota(P.begin(), P.end(), 0);

    int ans = INT_MAX;

    do {
        if (P[0] != 0) continue;

        {
            vector<vector<int>> now(n, vector<int>(n, 0));

            for (int i = 0; i < n; i++) {
                int u = P[i];
                int v = P[(i + 1) % n];
                now[u][v] = now[v][u] = 1;
            }

            int cost = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (exist[i][j] != now[i][j]) cost++;
                }
            }
            ans = min(ans, cost);
        }

        for (int d = 3; d <= n - 3; d++) {
            vector<vector<int>> now(n, vector<int>(n, 0));

            for (int i = 0; i < d; i++) {
                int u = P[i];
                int v = P[(i + 1) % d];
                now[u][v] = now[v][u] = 1;
            }

            for (int i = d; i < n; i++) {
                int u = P[i];
                int v = (i == n - 1 ? P[d] : P[i + 1]);
                now[u][v] = now[v][u] = 1;
            }

            int cost = 0;
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (exist[i][j] != now[i][j]) cost++;
                }
            }
            ans = min(ans, cost);
        }

    } while (next_permutation(P.begin(), P.end()));

    cout << ans << '\n';
}