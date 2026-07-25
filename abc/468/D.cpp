#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string S;
    cin >> S;
    int n = S.size();

    long long ans = 0;

    auto expand = [&](int left, int right) {
        int mismatch = 0;
        while (left >= 0 && right < n) {
            if (S[left] != S[right]) {
                mismatch++;
                if (mismatch >= 2) break; 
            }
            ans++;  
            left--;
            right++;
        }
    };

    for (int c = 0; c < n; c++) {
        expand(c, c);
    }

    for (int c = 0; c + 1 < n; c++) {
        expand(c, c + 1);
    }

    cout << ans << '\n';
}