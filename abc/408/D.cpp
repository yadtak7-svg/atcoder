#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        string S;
        cin >> S;

        int tot1 = 0;
        for (char c : S)
            if (c == '1') tot1++;

        int cur = 0;
        int best = 0;

        for (char c : S) {
            int x = (c == '1' ? 1 : -1);
            cur = max(0, cur + x);
            best = max(best, cur);
        }

        cout << tot1 - best << '\n';
    }
}