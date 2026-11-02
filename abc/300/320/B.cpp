#include <bits/stdc++.h>
using namespace std;

vector<int> manacher(const string &s) {
    int n = s.size();
    vector<int> radius(n);

    int i = 0, j = 0;

    while (i < n) {
        while (i - j >= 0 && i + j < n &&
               s[i - j] == s[i + j]) {
            ++j;
        }

        radius[i] = j;

        int k = 1;
        while (i - k >= 0 && i + k < n &&
               k + radius[i - k] < j) {
            radius[i + k] = radius[i - k];
            ++k;
        }

        i += k;
        j -= k;
    }

    return radius;
}

int main() {
    string s;
    cin >> s;

    string T(s.size() * 2 + 1, '#');

    for (int i = 0; i < s.size(); i++) {
        T[2 * i + 1] = s[i];
    }

    vector<int> P = manacher(T);

    int ans = 0;
    for (int x : P) {
        ans = max(ans, x - 1);
    }

    cout << ans << '\n';
}