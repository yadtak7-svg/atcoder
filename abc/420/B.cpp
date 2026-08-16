#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> score(n, 0);
    vector<string> S(n);

    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    for (int j = 0; j < m; j++) {

        int cnt0 = 0;
        for (int i = 0; i < n; i++) {
            if (S[i][j] == '0') {
                cnt0++;
            }
        }

        int sts;

        if (cnt0 == 0 || cnt0 == n) {
            sts = 0;
        }
        else if (2 * cnt0 > n) {
            sts = 1;
        }
        else {
            sts = 2;
        }
        for (int i = 0; i < n; i++) {
            if (sts == 0) {
                score[i]++;
            }
            else if (sts == 1 && S[i][j] == '1') {
                score[i]++;
            }
            else if (sts == 2 && S[i][j] == '0') {
                score[i]++;
            }
        }
    }

    int MAX = 0;
    for (int x : score) {
        MAX = max(MAX, x);
    }

    for (int i = 0; i < n; i++) {
        if (score[i] == MAX) {
            cout << i + 1 << ' ';
        }
    }

    cout << '\n';
}