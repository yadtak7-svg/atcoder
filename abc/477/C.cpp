#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    string S, T;
    cin >> S >> T;

    int N = S.size();
    int M = T.size();

    vector<int> pi(M);

    for (int i = 1; i < M; i++) {
        int j = pi[i - 1];

        while (j > 0 && T[i] != T[j]) {
            j = pi[j - 1];
        }

        if (T[i] == T[j]) {
            j++;
        }

        pi[i] = j;
    }

    vector<int> pos;

    int j = 0;

    for (int i = 0; i < N; i++) {
        while (j > 0 && S[i] != T[j]) {
            j = pi[j - 1];
        }

        if (S[i] == T[j]) {
            j++;
        }

        if (j == M) {
            pos.push_back(i - M + 1);
            j = pi[j - 1];
        }
    }

    while (Q--) {
        int l, r;
        cin >> l >> r;

        --l;
        --r;

        int right = r - M + 1;

        if (right < l) {
            cout << "No\n";
            continue;
        }

        auto it = lower_bound(pos.begin(), pos.end(), l);

        if (it != pos.end() && *it <= right) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
}